// Address: 0x1401ff390
// Ghidra name: FUN_1401ff390
// ============ 0x1401ff390 FUN_1401ff390 (size=390) ============


undefined1

FUN_1401ff390(longlong param_1,longlong param_2,undefined4 *param_3,undefined8 param_4,

             undefined4 param_5)



{

  undefined1 uVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  ulonglong uVar5;

  undefined8 in_stack_ffffffffffffffc0;

  undefined4 uVar6;

  undefined8 in_stack_ffffffffffffffd0;

  undefined4 uVar7;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffffc0 >> 0x20);

  uVar7 = (undefined4)((ulonglong)in_stack_ffffffffffffffd0 >> 0x20);

  lVar4 = *(longlong *)(param_2 + 0x138);

  if (lVar4 == 0) {

    uVar1 = FUN_14012e850("Texture is not currently available");

    return uVar1;

  }

  uVar5 = (ulonglong)*(uint *)(lVar4 + 0x24);

  iVar3 = FUN_140200040(uVar5);

  if (iVar3 == 2) {

    FUN_1401fa4f0(uVar5 & 0xffffffff,1);

    uVar1 = FUN_1401ff7b0(param_1,param_2);

    return uVar1;

  }

  if (iVar3 == 3) {

    uVar1 = FUN_1401ff8e0(param_1,param_2);

    return uVar1;

  }

  cVar2 = FUN_1401ff520(*(undefined8 *)(param_1 + 0x2e0),*(undefined8 *)(lVar4 + 8),

                        uVar5 & 0xffffffff,0,*param_3,CONCAT44(uVar6,param_3[1]),param_3[2],

                        CONCAT44(uVar7,param_3[3]),param_4,param_5,lVar4 + 0x20);

  return cVar2 != '\0';

}




