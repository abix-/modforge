// Address: 0x1401792e0
// Ghidra name: FUN_1401792e0
// ============ 0x1401792e0 FUN_1401792e0 (size=125) ============


undefined8 FUN_1401792e0(undefined8 *param_1,char *param_2)



{

  char cVar1;

  undefined8 uVar2;

  undefined8 local_res8;

  

  uVar2 = 0;

  if (((param_1 != (undefined8 *)0x0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {

    FUN_140179b40(*param_1);

    cVar1 = FUN_1401aaff0(param_1[1],param_2,&local_res8);

    if (cVar1 != '\0') {

      uVar2 = FUN_1401aa890(local_res8);

    }

    FUN_140179b60(*param_1);

    return uVar2;

  }

  return 0;

}




