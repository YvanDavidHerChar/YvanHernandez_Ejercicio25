N := 10000
mu := 5
sigma := 0.3

sample.pdf: sample.dat
	python graficando.py sample.dat $(mu) $(sigma)

sample.dat: sample.x
	./sample.x $(N) $(mu) $(sigma)

sample.x: sample.c
	gcc sample.c -lm -o sample.x

clean: 
	rm -f *.dat *.pdf *.x 
