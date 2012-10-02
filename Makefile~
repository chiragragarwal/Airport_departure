VARIABLE_FILE = -include "variables.c"
BAGGAGE_FILE = -include "baggage/bag_new.c"
IMG_FILE = -include "immigration/immigration.c"
SEC_FILE = -include "security_check/security.c"
WAIT_FILE = -include "wait_lounge/wait_lounge.c"
BP_FILE = -include "board_pass/board_pass.c"

INCLUDE_ALL = $(VARIABLE_FILE) $(BAGGAGE_FILE) $(IMG_FILE) $(SEC_FILE) $(WAIT_FILE) $(BP_FILE)

code:
	gcc $(INCLUDE_ALL) -o airport airport.c
	
clean:
	rm -r Ids.txt Imm_Status.txt ./baggage/bag_Ids.txt ./board_pass/wait_count.txt ./immigration/imm_Ids.txt
	rm -r ./immigration/Pass_Status.txt ./immigration/Visa_Status.txt
	rm -r ./security_check/sec_Ids.txt ./wait_lounge/count.txt ./wait_lounge/wait_Ids.txt
	rm ./baggage/passengers/*
