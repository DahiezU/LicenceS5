#ifndef p_avl_h_included
#define p_avl_h_included

/**
 * \file p_avl.h
 *
 *
 * \brief les �l�ments sont des chaines de caract�res.
 *   on dispose d'une relation d'ordre sur les chaines : l'ordre lexicographique.
 *   il s'agit de l'ordre du dictionnaire (appel� de mani�re impropre l'ordre alphab�tiques).
 *   on pourra utiliser :
 *       - soit la fonction compare_chaine faite en tp de remise en route.
 *       - soit la fonction strcmp disponible dans la biblioth�que string.h
 *
 * \author weinberg benjamin
 * \version 0.5
 * \date septembre 2019


 * la structure en avl, permet de g�rer des abo.
 * dont le d�s�quilibre n'est pas trop important
 * on doit cette structure � adelson-velskii et landis

 * \warning attention cette bibliotheque manipule des pointeurs.
    il faut faire attention qu'on lib�re correctement la m�moire
    on veuillera �galement � ne pas utiliser pas un pointeur qui pointe sur zone m�moire non allou�e (ou qui n'est plus allou�).

 * \warning dans ce tp, on ne mettra pas en place tous les mecanismes permettant de garantir l'int�grit� des processus.
    en effet, le langage c fournit trop de moyen de d�tourner les securit�s qu'on vourdrait mettre en place.

 */


#include <stdlib.h>
#include "../utilitaires/p_utilitaires.h"
#include "../element_string/p_element_string.h"


#define AVL_VIDE NULL

typedef struct s_noeud_avl{
    t_element l_etiquette;
    struct s_noeud_avl* la_gauche;
    struct s_noeud_avl* la_droite;
    int la_hauteur;
}t_noeud_avl;

typedef t_noeud_avl* a_noeud_avl;
typedef a_noeud_avl t_avl;

/**
 * \brief alloue un noeud et rempli les diff�rents champs.
 * cette fonction devrait �tre utilis�r uniquement pour cr�er une feuille
 * cette fonction devait donc �tre masqu�e � terme.
 *
 * \param etiquette : t_element : la valeur � la racine.
 * \param gauche : t_avl : le sous arbre gauche.
 * \param droite : t_avl : le sous arbre droit.
 * \return a_noeud_avl : le nouveau noeud construit
 */
a_noeud_avl nouveau_noeud(t_element etiquette, t_avl gauche, t_avl droite);


/**
 * \brief affiche un avl un peu comme un arbre mais avec en faisant apparaitre l'information de hauteur en plus.
 *
 * \param ceci: t_avl : l'arbre � afficher.
 * \param d�calage : int : le niveau d'indentation de l'arbre.
 * \return rien.
 */
void afficher_avl(t_avl ceci, int decalage);

/**
 * \brief retourne la hauteur de ceci.
 * la fonction est simple car l'information est g�n�ralement disponible dans la racine.
 *
 * \param ceci: t_avl : l'arbre dont on cherche la hauteur.
 * \return rien.
 */
int hauteur_avl(t_avl ceci);

/**
 * \brief met � jour la hauteur de ceci.
 * dans un arbre non vide la hauteur d'un avl est d�duite de la hauteur de ses fils.
 *
 * \param ceci: t_avl : l'arbre dont on met � jour la hauteur.
 * \warning : ceci est non vide !
 * \return rien.
 */
void mettre_a_jour_hauteur(t_avl ceci);

/**
 * \brief retourne la diff�rence de hauteur entre le fils droit et le fils gauche.
 * \warning dans un avl le d�s�quibre doit �tre compris entre -1 (l'arbre penche � gauche) et +1 (l'arbre penche � droite)
 *
 * \param ceci: t_avl : l'arbre dont on calcule le d�s�quilibre.
 * \return int : le d�s�quilibre.
 */
int desequilibre(t_avl ceci);


/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les m�mes informations mais penchant moins � droite.
 * les rotations pr�servent la structure d'abo mais change l'�quilibrage.
 * elles sont utilis�es pour r��quilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl � modifier
 * \return : rien
 */
void rotation_gauche(t_avl* ceci);

/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les m�mes informations mais penchant moins � gauche.
 * les rotations pr�servent la structure d'abo mais change l'�quilibrage.
 * elles sont utilis�es pour r��quilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl � modifier
 * \return : rien
 */
void rotation_droite(t_avl* ceci);

/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les m�mes informations mais penchant moins � droite.
 * les rotations pr�servent la structure d'abo mais change l'�quilibrage.
 * elles sont utilis�es pour r��quilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl � modifier
 * \return : rien
 */
void rotation_droite_gauche(t_avl* ceci);

/**
 * \brief modifie *ceci pour qu'il pointe sur arbre avec les m�mes informations mais penchant moins � gauche.
 * les rotations pr�servent la structure d'abo mais change l'�quilibrage.
 * elles sont utilis�es pour r��quilibrer un avl lors d'une insertion
 *
 * \param *ceci : t_avl � modifier
 * \return : rien
 */
void rotation_gauche_droite(t_avl* ceci);

/**
 * \brief insert un �l�ment comme une feuille de l'arbre *dans comme un abo
 * et r��quilibre le long de la branche d'insertion pour que la struction avl soit respect�e.
 *
 * \param *ceci : t_avl � modifier
 * \return : rien
 */
void inserer_avl(t_element quoi, t_avl* dans);

#endif // p_avl_h_included
