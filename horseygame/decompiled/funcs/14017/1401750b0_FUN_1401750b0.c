// Address: 0x1401750b0
// Ghidra name: FUN_1401750b0
// ============ 0x1401750b0 FUN_1401750b0 (size=292) ============


undefined8 FUN_1401750b0(int param_1,char *param_2,longlong param_3)



{

  char cVar1;

  longlong lVar2;

  undefined8 uVar3;

  char *pcVar4;

  undefined8 *local_res20;

  

  local_res20 = (undefined8 *)0x0;

  uVar3 = 1;

  if (param_1 != 0) {

    if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

      FUN_140174970(0,param_3,0,1);

      pcVar4 = "name";

      goto LAB_1401751b8;

    }

    FUN_1401aaff0(DAT_1403fc450,param_1,&local_res20);

    if (local_res20 != (undefined8 *)0x0) {

      FUN_140179b40(local_res20[1]);

      FUN_1401ab340(*local_res20,param_2);

      if (param_3 != 0) {

        lVar2 = FUN_14012f0d0(param_2);

        if (lVar2 != 0) {

          cVar1 = FUN_1401ab100(*local_res20,lVar2,param_3,0);

          if (cVar1 != '\0') goto LAB_14017517e;

        }

        FUN_140174970(lVar2,param_3,0,1);

        uVar3 = 0;

      }

LAB_14017517e:

      FUN_140179b60(local_res20[1]);

      return uVar3;

    }

  }

  FUN_140174970(0,param_3,0,1);

  pcVar4 = "props";

LAB_1401751b8:

  uVar3 = FUN_14012e850("Parameter \'%s\' is invalid",pcVar4);

  return uVar3;

}




