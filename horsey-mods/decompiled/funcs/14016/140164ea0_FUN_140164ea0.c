// Address: 0x140164ea0
// Ghidra name: FUN_140164ea0
// ============ 0x140164ea0 FUN_140164ea0 (size=182) ============


ulonglong FUN_140164ea0(undefined8 *param_1,undefined8 param_2,uint param_3,undefined8 param_4,

                       undefined8 param_5)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  

  FUN_140179b40(*param_1);

  cVar1 = FUN_140163e40(param_1);

  if (cVar1 == '\0') {

    uVar3 = FUN_140179b60(*param_1);

    uVar3 = uVar3 & 0xffffffffffffff00;

  }

  else if (param_3 % ((*(uint *)(param_1 + 6) >> 3 & 0x1f) * *(int *)((longlong)param_1 + 0x34)) ==

           0) {

    bVar2 = FUN_140164f60(param_1,param_1 + 6,param_1[9],param_2,param_3,param_4,param_5);

    FUN_140179b60(*param_1);

    uVar3 = (ulonglong)bVar2;

  }

  else {

    FUN_140179b60(*param_1);

    uVar3 = FUN_14012e850("Can\'t add partial sample frames");

  }

  return uVar3;

}




