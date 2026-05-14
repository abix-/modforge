// Address: 0x140174dd0
// Ghidra name: FUN_140174dd0
// ============ 0x140174dd0 FUN_140174dd0 (size=148) ============


undefined4 FUN_140174dd0(int param_1,char *param_2)



{

  char cVar1;

  undefined4 uVar2;

  undefined8 *local_res18;

  undefined4 *local_res20;

  

  uVar2 = 0;

  local_res18 = (undefined8 *)0x0;

  if (((param_1 != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {

    FUN_1401aaff0(DAT_1403fc450,param_1,&local_res18);

    if (local_res18 != (undefined8 *)0x0) {

      FUN_140179b40(local_res18[1]);

      local_res20 = (undefined4 *)0x0;

      cVar1 = FUN_1401aaff0(*local_res18,param_2,&local_res20);

      if (cVar1 != '\0') {

        uVar2 = *local_res20;

      }

      FUN_140179b60(local_res18[1]);

      return uVar2;

    }

  }

  return 0;

}




