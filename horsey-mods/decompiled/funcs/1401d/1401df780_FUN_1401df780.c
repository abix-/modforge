// Address: 0x1401df780
// Ghidra name: FUN_1401df780
// ============ 0x1401df780 FUN_1401df780 (size=190) ============


undefined1 FUN_1401df780(longlong param_1,int param_2)



{

  longlong lVar1;

  undefined1 uVar2;

  char cVar3;

  int iVar4;

  uint uVar5;

  undefined1 local_138 [20];

  uint local_124;

  

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  if (param_2 == 0) {

    uVar5 = 0x80000000;

  }

  else if (param_2 == 1) {

    uVar5 = 1;

  }

  else if (param_2 == 2) {

    uVar5 = 2;

  }

  else if (param_2 == 3) {

    uVar5 = 4;

  }

  else {

    if (param_2 != 4) goto LAB_1401df7b4;

    uVar5 = 8;

  }

  iVar4 = (**(code **)(**(longlong **)(lVar1 + 8) + 0x70))

                    (*(longlong **)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x18),1,local_138);

  if (iVar4 < 0) {

    uVar2 = FUN_1401df290("GetDeviceCaps()",iVar4);

    return uVar2;

  }

  if ((local_124 & uVar5) != 0) {

    *(uint *)(lVar1 + 0x5c) = uVar5;

    cVar3 = FUN_1401de770(param_1);

    return cVar3 != '\0';

  }

LAB_1401df7b4:

  uVar2 = FUN_14012e850("That operation is not supported");

  return uVar2;

}




