// Address: 0x14026d5b0
// Ghidra name: FUN_14026d5b0
// ============ 0x14026d5b0 FUN_14026d5b0 (size=177) ============


bool FUN_14026d5b0(longlong param_1,undefined4 param_2,undefined8 param_3,undefined1 param_4,

                  longlong *param_5)



{

  char cVar1;

  longlong lVar2;

  int iVar3;

  undefined1 local_58 [64];

  

  lVar2 = 0;

  iVar3 = 1;

  do {

    if (*(int *)(param_1 + 0x1c) < iVar3) break;

    FUN_1402692c0(param_1,param_2,param_3,param_4,local_58);

    cVar1 = FUN_14026d3d0(param_1,local_58,0x31);

    if (cVar1 != '\0') {

      lVar2 = FUN_14026c980(param_1,param_2,param_3,param_4);

    }

    iVar3 = iVar3 + 1;

  } while (lVar2 == 0);

  if (param_5 != (longlong *)0x0) {

    *param_5 = lVar2;

  }

  return lVar2 != 0;

}




