// Address: 0x14013dcb0
// Ghidra name: FUN_14013dcb0
// ============ 0x14013dcb0 FUN_14013dcb0 (size=252) ============


void FUN_14013dcb0(undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)



{

  longlong lVar1;

  longlong *plVar2;

  undefined1 local_28 [16];

  undefined1 local_18 [16];

  

  FUN_140159d30();

  for (plVar2 = DAT_1403fbef8; plVar2 != (longlong *)0x0; plVar2 = (longlong *)plVar2[10]) {

    lVar1 = *plVar2;

    if ((*(longlong *)(lVar1 + 0xf8) != 0) && (*(int *)(lVar1 + 0xf4) == param_2)) {

      FUN_14013c030(lVar1,param_4,local_28);

      FUN_14015afd0(param_1,*plVar2,1,param_3,local_28,3);

    }

    lVar1 = *plVar2;

    if ((*(longlong *)(lVar1 + 0x108) != 0) && (*(int *)(lVar1 + 0x100) == param_2)) {

      FUN_14013c030(lVar1,param_4,local_18);

      FUN_14015afd0(param_1,*plVar2,2,param_3,local_18,3);

    }

  }

  FUN_14015bb10();

  return;

}




