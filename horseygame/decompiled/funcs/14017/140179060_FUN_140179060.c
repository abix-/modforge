// Address: 0x140179060
// Ghidra name: FUN_140179060
// ============ 0x140179060 FUN_140179060 (size=155) ============


undefined8 FUN_140179060(longlong *param_1,undefined8 param_2,char *param_3,char *param_4)



{

  undefined1 *puVar1;

  size_t sVar2;

  

  sVar2 = strlen(param_3);

  *(longlong *)(*param_1 + param_1[2] * 8) = param_1[1];

  FUN_1402f8e20(param_1[1],param_3,sVar2);

  param_1[1] = param_1[1] + sVar2;

  *(undefined1 *)param_1[1] = 0x3d;

  param_1[1] = param_1[1] + 1;

  sVar2 = strlen(param_4);

  FUN_1402f8e20(param_1[1],param_4,sVar2);

  param_1[1] = param_1[1] + sVar2;

  puVar1 = (undefined1 *)param_1[1];

  *puVar1 = 0;

  param_1[1] = param_1[1] + 1;

  param_1[2] = param_1[2] + 1;

  return CONCAT71((int7)((ulonglong)puVar1 >> 8),1);

}




