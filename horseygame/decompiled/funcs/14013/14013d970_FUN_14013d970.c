// Address: 0x14013d970
// Ghidra name: FUN_14013d970
// ============ 0x14013d970 FUN_14013d970 (size=115) ============


void FUN_14013d970(longlong param_1)



{

  longlong lVar1;

  undefined8 uVar2;

  longlong *plVar3;

  

  _guard_check_icall();

  plVar3 = DAT_1403fbef8;

  if (DAT_1403fbef8 != (longlong *)0x0) {

    while (*plVar3 != param_1) {

      plVar3 = (longlong *)plVar3[10];

      if (plVar3 == (longlong *)0x0) {

        return;

      }

    }

    FUN_140141d70(0,plVar3,5,0);

    lVar1 = *plVar3;

    if (*(longlong *)(lVar1 + 0x138) == 0) {

      uVar2 = FUN_140149300();

      *(undefined8 *)(lVar1 + 0x138) = uVar2;

    }

  }

  return;

}




