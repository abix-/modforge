// Address: 0x1401f9a50
// Ghidra name: FUN_1401f9a50
// ============ 0x1401f9a50 FUN_1401f9a50 (size=355) ============


void FUN_1401f9a50(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  

  lVar1 = *(longlong *)(param_2 + 0x138);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 != 0) {

    FUN_1401fabf0(lVar2);

    FUN_1402000b0(lVar2);

    FUN_1401f9930(lVar2,lVar1);

    if (*(longlong *)(lVar1 + 0x78) != 0) {

      (*DAT_1403fd188)(*(undefined8 *)(lVar2 + 0x660),*(longlong *)(lVar1 + 0x78),0);

      *(undefined8 *)(lVar1 + 0x78) = 0;

    }

    if (*(longlong *)(lVar1 + 0x80) != 0) {

      (*DAT_1403fd010)(*(undefined8 *)(lVar2 + 0x660),*(longlong *)(lVar1 + 0x80),0);

      *(undefined8 *)(lVar1 + 0x80) = 0;

    }

    if (*(longlong *)(lVar1 + 0x90) != 0) {

      (*DAT_1403fd000)(*(undefined8 *)(lVar2 + 0x660),*(longlong *)(lVar1 + 0x90),0);

      *(undefined8 *)(lVar1 + 0x90) = 0;

    }

    if (*(longlong *)(lVar1 + 0x88) != 0) {

      (*DAT_1403fcfd0)(*(undefined8 *)(lVar2 + 0x660),*(longlong *)(lVar1 + 0x88),0);

      *(undefined8 *)(lVar1 + 0x88) = 0;

    }

    FUN_1401f98d0(lVar2,lVar1 + 0x40);

    if (*(longlong *)(lVar1 + 0x38) != 0) {

      (*DAT_1403fcfe0)(*(undefined8 *)(lVar2 + 0x660),*(longlong *)(lVar1 + 0x38),0);

      *(undefined8 *)(lVar1 + 0x38) = 0;

    }

    if (*(longlong *)(lVar1 + 0x28) != 0) {

      (*DAT_1403fd008)(*(undefined8 *)(lVar2 + 0x660),*(longlong *)(lVar1 + 0x28),0);

      *(undefined8 *)(lVar1 + 0x28) = 0;

    }

    if (*(longlong *)(lVar1 + 0x30) != 0) {

      (*DAT_1403fd008)(*(undefined8 *)(lVar2 + 0x660),*(longlong *)(lVar1 + 0x30),0);

      *(undefined8 *)(lVar1 + 0x30) = 0;

    }

    FUN_1401841e0(lVar1);

    *(undefined8 *)(param_2 + 0x138) = 0;

  }

  return;

}




