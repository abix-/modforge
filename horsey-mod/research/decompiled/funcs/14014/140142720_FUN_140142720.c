// Address: 0x140142720
// Ghidra name: FUN_140142720
// ============ 0x140142720 FUN_140142720 (size=163) ============


void FUN_140142720(undefined8 param_1,undefined4 param_2,undefined8 param_3)



{

  char *_Str2;

  undefined8 *puVar1;

  undefined8 *puVar2;

  int iVar3;

  undefined8 *puVar4;

  char *_Str1;

  

  puVar4 = (undefined8 *)FUN_140174d30(param_2,param_3,0);

  if (puVar4 == (undefined8 *)0x0) {

    return;

  }

  _Str1 = (char *)FUN_140142630(param_3);

  _Str2 = (char *)*puVar4;

  if (_Str1 == (char *)0x0) {

    if (_Str2 == (char *)0x0) goto LAB_1401427a3;

  }

  else if ((_Str2 != (char *)0x0) && (iVar3 = strcmp(_Str1,_Str2), iVar3 == 0)) goto LAB_1401427a3;

  puVar2 = (undefined8 *)puVar4[2];

  while (puVar2 != (undefined8 *)0x0) {

    puVar1 = (undefined8 *)puVar2[2];

    (*(code *)*puVar2)(puVar2[1],param_3,*puVar4,_Str1);

    puVar2 = puVar1;

  }

LAB_1401427a3:

  FUN_1401841e0(*puVar4);

  *puVar4 = 0;

  *(undefined4 *)(puVar4 + 1) = 0;

  return;

}




