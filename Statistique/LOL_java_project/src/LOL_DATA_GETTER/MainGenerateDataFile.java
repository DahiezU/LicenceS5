package LOL_DATA_GETTER;
import java.io.File;

import java.util.ArrayList;
import org.json.simple.JSONObject;

/**
 * @author akarami
 *
 */

public class MainGenerateDataFile {

	public static final String MATCHES_FILES_DIRECTORY = "files/matches/";
	public static final String OUTPUT_DATA_DIRECTORY = "files/data/";
	
	
	public static void main(String[] args) throws Exception {
		
		//get the list of matches ids from the files name in the matches info directory
		File matchesFolder = new File(MATCHES_FILES_DIRECTORY);
		ArrayList<String> listMatchesID = new ArrayList<String>();
		for (File fileEntry : matchesFolder.listFiles()) {
			String[] parts = fileEntry.getName().split("_");
			if(parts[1].startsWith("match"))
				listMatchesID.add(parts[0]);
		}
		
		System.out.println("Total number of matches " + listMatchesID.size());
		String output = "gameDuration,"
				+ "championID1, championLevel1, kills1, deaths1, assists1, minionsKill1, gold1, lane1, "
				+ "championID2, championLevel2, kills2, deaths2, assists2, minionsKill2, gold2, lane2, "
				+ "championID3, championLevel3, kills3, deaths3, assists3, minionsKill3, gold3, lane3, "
				+ "championID4, championLevel4, kills4, deaths4, assists4, minionsKill4, gold4, lane4, "
				+ "championID5, championLevel5, kills5, deaths5, assists5, minionsKill5, gold5, lane5, "
				+ "inhibitorKillsTeam1, dragonKillsTeam1, baronKillsTeam1, towerKillsTeams1, winTeam1, "
				+ "championID6, championLevel6, kills6, deaths6, assists6, minionsKill6, gold6, lane6, "
				+ "championID7, championLevel7, kills7, deaths7, assists7, minionsKill7, gold7, lane7, "
				+ "championID8, championLevel8, kills8, deaths8, assists8, minionsKill8, gold8, lane8, "
				+ "championID9, championLevel9, kills9, deaths9, assists9, minionsKill9, gold9, lane9, "
				+ "championID10, championLevel10, kills10, deaths10, assists10, minionsKill10, gold10, lane10,"
				+ "inhibitorKillsTeam2, dragonKillsTeam2, baronKillsTeam2, towerKillsTeams2,winTeam2 \n";
		ReadWriteFiles.writeLineToFile(output,  OUTPUT_DATA_DIRECTORY+"player_team_lol_data.csv");
	   	//Treate all matches
		for (String matchId : listMatchesID){
			output = "";
			JSONObject matchData = ReadWriteFiles.readJsonFromFile(MATCHES_FILES_DIRECTORY + "" + matchId + "_match.JSON");
//			JSONObject matchTimelines = ReadWriteFiles.readJsonFromFile(MATCHES_FILES_DIRECTORY + "" + matchId + "_timelines.JSON");
			System.out.println("match id = " + matchId + " treated");
			
			//get data from match file
			long duration = MatchDataTreatement.getGameDuration(matchData);
			
			//Participant related information	
			long[] championID = MatchDataTreatement.getChampionID(matchData);
			long[] championLevel = MatchDataTreatement.getFromMatchParticipantStat(matchData, "champLevel");
			long[] kills = MatchDataTreatement.getFromMatchParticipantStat(matchData, "kills");
			long[] deaths = MatchDataTreatement.getFromMatchParticipantStat(matchData, "deaths");
			long[] assists = MatchDataTreatement.getFromMatchParticipantStat(matchData, "assists");
			long[] minionskill = MatchDataTreatement.getFromMatchParticipantStat(matchData, "totalMinionsKilled");
			long[] gold = MatchDataTreatement.getFromMatchParticipantStat(matchData, "goldEarned");
			String[] lane = MatchDataTreatement.getLane(matchData);
			
			
			//team related information
			long[] inhibitorKills = MatchDataTreatement.getFromMatchTeams(matchData, "inhibitorKills");
			long[] dragonKills = MatchDataTreatement.getFromMatchTeams(matchData, "dragonKills");
			long[] baronKills = MatchDataTreatement.getFromMatchTeams(matchData, "baronKills");
			long[] towerKills = MatchDataTreatement.getFromMatchTeams(matchData, "towerKills");
			String[] win = MatchDataTreatement.getFromMatchTeamsString(matchData, "win");
			
			
			output += duration + ", ";
			//regroup information about first 5 players	
			for (int p=0; p<5; p++) {
				output += championID[p] + ", " + championLevel[p] + ", " + kills[p] + ", " + deaths[p] + ", " 
						+ assists[p] + ", " +minionskill[p] + ", " + gold[p] + ", " + lane[p] + ", ";
			}
			//regroup information about the first team
			output += inhibitorKills[0] + ", " + dragonKills[0] + ", " + baronKills[0] + ", " + towerKills[0] + ", " 
						+ win[0] + ", ";

			//regroup information about players of the second team
			for (int p=5; p<10; p++) {
				output += championID[p] + ", " + championLevel[p] + ", " + kills[p] + ", " + deaths[p] + ", " 
						+ assists[p] + ", " +minionskill[p] + ", " + gold[p] + ", " + lane[p] + ", ";
			}
			//regroup information about the second team
			output += inhibitorKills[1] + ", " + dragonKills[1] + ", " + baronKills[1] + ", " + towerKills[1] + ", " 
						+ win[1] + "\n";
			//print data line into file
			ReadWriteFiles.writeLineToFile(output,  OUTPUT_DATA_DIRECTORY+"player_team_lol_data.csv");
		}
	}
}
			
			
					