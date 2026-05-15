// Address: 0x140106ac0
// Ghidra name: FUN_140106ac0
// ============ 0x140106ac0 FUN_140106ac0 (size=187) ============


undefined8 FUN_140106ac0(longlong param_1)



{

  longlong lVar1;

  longlong lVar2;

  int iVar3;

  

  iVar3 = FUN_1400c6580(0xc);

  if (*(longlong *)(*(longlong *)(param_1 + 0x438) + 8 + (longlong)iVar3 * 8) == 0) {

    iVar3 = FUN_1400c6580(7);

  }

  lVar1 = (longlong)(iVar3 + 1) * 8;

  lVar2 = *(longlong *)(lVar1 + *(longlong *)(param_1 + 0x438));

  if (lVar2 != 0) {

    iVar3 = (int)(*(longlong *)(lVar2 + 0x138) - (longlong)*(undefined8 **)(lVar2 + 0x130) >> 3);

    if (iVar3 != 0) {

      if (iVar3 == 1) {

        return **(undefined8 **)(lVar2 + 0x130);

      }

      iVar3 = FUN_1400c6580(iVar3 + -1);

      return *(undefined8 *)

              (*(longlong *)(*(longlong *)(*(longlong *)(param_1 + 0x438) + lVar1) + 0x130) + 8 +

              (longlong)iVar3 * 8);

    }

  }

  return 0;

}




