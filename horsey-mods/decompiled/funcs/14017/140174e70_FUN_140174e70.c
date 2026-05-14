// Address: 0x140174e70
// Ghidra name: FUN_140174e70
// ============ 0x140174e70 FUN_140174e70 (size=332) ============


char * FUN_140174e70(int param_1,char *param_2,char *param_3)



{

  int iVar1;

  char cVar2;

  char *pcVar3;

  int *local_res18;

  undefined8 *local_res20;

  

  local_res20 = (undefined8 *)0x0;

  pcVar3 = param_3;

  if ((((param_1 != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) &&

     (FUN_1401aaff0(DAT_1403fc450,param_1,&local_res20), local_res20 != (undefined8 *)0x0)) {

    FUN_140179b40(local_res20[1]);

    local_res18 = (int *)0x0;

    cVar2 = FUN_1401aaff0(*local_res20,param_2,&local_res18);

    if (cVar2 != '\0') {

      iVar1 = *local_res18;

      if (iVar1 == 2) {

        pcVar3 = *(char **)(local_res18 + 2);

      }

      else if (iVar1 == 3) {

        pcVar3 = *(char **)(local_res18 + 4);

        if (pcVar3 == (char *)0x0) {

          FUN_14012ee40(local_res18 + 4,"%I64d",*(undefined8 *)(local_res18 + 2));

          pcVar3 = param_3;

          if (*(char **)(local_res18 + 4) != (char *)0x0) {

            pcVar3 = *(char **)(local_res18 + 4);

          }

        }

      }

      else if (iVar1 == 4) {

        pcVar3 = *(char **)(local_res18 + 4);

        if (pcVar3 == (char *)0x0) {

          FUN_14012ee40(local_res18 + 4,&DAT_1403356b0,(double)(float)local_res18[2]);

          pcVar3 = param_3;

          if (*(char **)(local_res18 + 4) != (char *)0x0) {

            pcVar3 = *(char **)(local_res18 + 4);

          }

        }

      }

      else if ((iVar1 == 5) && (pcVar3 = "false", (char)local_res18[2] != '\0')) {

        pcVar3 = "true";

      }

    }

    FUN_140179b60(local_res20[1]);

  }

  return pcVar3;

}




