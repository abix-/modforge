// Address: 0x1401637d0
// Ghidra name: FUN_1401637d0
// ============ 0x1401637d0 FUN_1401637d0 (size=205) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 * FUN_1401637d0(char param_1)



{

  undefined8 *puVar1;

  code *local_res10;

  undefined8 local_res18 [2];

  

  puVar1 = (undefined8 *)FUN_1401638b0(&DAT_1403fc400);

  if (puVar1 == (undefined8 *)0x0) {

    if (param_1 == '\0') {

      return (undefined8 *)0x0;

    }

    FUN_1401840e0(0,0,&local_res10,local_res18);

    puVar1 = (undefined8 *)(*local_res10)(0,0x28);

    if (puVar1 == (undefined8 *)0x0) {

      _DAT_1403fc368 = 0x80;

      _DAT_1403fc360 = &DAT_1403fc380;

      return (undefined8 *)&DAT_1403fc358;

    }

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[3] = local_res10;

    puVar1[4] = local_res18[0];

    FUN_140163ac0(&DAT_1403fc400,puVar1,FUN_1401635c0);

  }

  return puVar1;

}




