urnsamples(1:3, size = 3, replace = TRUE, ordered = TRUE)

outcomes <- tosscoin(20)
p<-rep(7/10, times = 1) 
p1<-rep(3/10, times = 1)
probspace(outcomes, probs=c(p, p1))


r <- rolldie(3)
#subset(r, )