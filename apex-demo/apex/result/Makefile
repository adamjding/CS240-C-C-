APEX=/homes/cs240/2018Spring/lab-apex/apex-bin/
BINDIR=$(APEX)/apex
DIR_A = ../A
DIR_B = ../B
SYMB_A = $(DIR_A)/symb.out
SYMB_B = $(DIR_B)/symb.out
CFG_A = $(DIR_A)/cfg.out
CFG_B = $(DIR_B)/cfg.out

.PHONY: all clean align explain report maxsat component

all: explain # component #align.out

# factor:
# 	$(BINDIR)/factor.py

# component: $(SYMB_A) $(SYMB_B) ../precond align.out
# 	$(APEX)/script/component.py -symbA $(SYMB_A) -symbB $(SYMB_B) -align align.out

cmpins.out: $(SYMB_A) $(SYMB_B)
	PYTHONPATH=${APEX}/lib $(BINDIR)/compare_symb.py -symbA $(SYMB_A) -symbB $(SYMB_B) -out $@ -log compare.log

# cmpins.prune.out: $(SYMB_A) $(SYMB_B) cmpins.out
# 	$(BINDIR)/prune_compare.py -symbA $(SYMB_A) -symbB $(SYMB_B) -cmp cmpins.out -out cmpins.prune.out

align.out: $(SYMB_A) $(SYMB_B) cmpins.out
	# /usr/bin/time -p -o align.out.time $(BINDIR)/align-b1.py -symbA $(SYMB_A) -symbB $(SYMB_B) -cmpins cmpins.out -cmpout cmpins.1 -out align.out -log align.log
	PYTHONPATH=${APEX}/lib $(BINDIR)/align-xx.py

align: cmpins.out
	# $(BINDIR)/align-b1.py -symbA $(SYMB_A) -symbB $(SYMB_B) -cmpins cmpins.out -cmpout cmpins.1 -out align.out -log align.log
	PYTHONPATH=${APEX}/lib $(BINDIR)/align-xx.py

fac.0.py: align.out
	PYTHONPATH=${APEX}/lib $(BINDIR)/generate3.py -a -o fac.0.py

bp.0: fac.0.py
	PYTHONPATH=${APEX}/lib ./fac.0.py -o bp.0

bp.align: bp.0
	PYTHONPATH=${APEX}/lib $(BINDIR)/bp2align.py bp.0 bp.align

explain: bp.align
	PYTHONPATH=${APEX}/lib $(BINDIR)/explain.py -align bp.align


clean:
	${RM} -f explain.out explain4.out align.out cmpins.out src.out *.x *.log cmpins.1 align.[12] align.[12][xy] maxsat.* soft tscore apexscore z3score WPM3.out *.time *.out fac.py bp.*

maxsat.out: $(SYMB_A) $(SYMB_B) cmpins.prune.out
	/usr/bin/time -p -o time.1 $(APEX)/script/maxsat.py -symbA $(SYMB_A) -symbB $(SYMB_B) -cmpins cmpins.prune.out -out maxsat.out

z3.out: maxsat.out
	/usr/bin/time -p -o time.2 ~/workspace/onlineedu/z3/build/z3 -T:300 maxsat.out > z3.out

# align-z3.out: z3.out
# 	$(APEX)/script/check_sat.py -symbA $(SYMB_A) -symbB $(SYMB_B)

check: z3.out
	$(APEX)/script/check_sat.py -symbA $(SYMB_A) -symbB $(SYMB_B)
	$(APEX)/script/check-align.py | tee maxsat_score


.DELETE_ON_ERROR:
