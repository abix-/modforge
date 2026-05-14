// Address: 0x140174d30
// Ghidra name: FUN_140174d30
// ============ 0x140174d30 FUN_140174d30 (size=153) ============


undefined8 FUN_140174d30(int param_1,char *param_2,undefined8 param_3)



{

  char cVar1;

  undefined8 *local_res18;

  int *local_res20;

  

  local_res18 = (undefined8 *)0x0;

  if (((param_1 != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {

    FUN_1401aaff0(DAT_1403fc450,param_1,&local_res18);

    if (local_res18 != (undefined8 *)0x0) {

      FUN_140179b40(local_res18[1]);

      local_res20 = (int *)0x0;

      cVar1 = FUN_1401aaff0(*local_res18,param_2,&local_res20);

      if ((cVar1 != '\0') && (*local_res20 == 1)) {

        param_3 = *(undefined8 *)(local_res20 + 2);

      }

      FUN_140179b60(local_res18[1]);

    }

  }

  return param_3;

}




