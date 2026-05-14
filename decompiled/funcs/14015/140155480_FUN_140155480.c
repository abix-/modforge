// Address: 0x140155480
// Ghidra name: FUN_140155480
// ============ 0x140155480 FUN_140155480 (size=138) ============


ulonglong FUN_140155480(longlong param_1)



{

  ulonglong uVar1;

  longlong lVar2;

  ulonglong in_RAX;

  ulonglong uVar3;

  

  uVar1 = *(ulonglong *)(param_1 + 0x128);

  if (uVar1 != 0) {

    in_RAX = FUN_140149300();

    uVar3 = in_RAX - *(longlong *)(param_1 + 0x130);

    if (uVar3 < uVar1) {

      FUN_140149210(uVar1 - uVar3);

      in_RAX = FUN_140149300();

    }

    lVar2 = *(longlong *)(param_1 + 0x130);

    uVar3 = in_RAX - lVar2;

    if ((lVar2 != 0) && (uVar3 < 0x3b9aca01)) {

      *(ulonglong *)(param_1 + 0x130) = (lVar2 - uVar3 % uVar1) + uVar3;

      return uVar3 / uVar1;

    }

    *(ulonglong *)(param_1 + 0x130) = in_RAX;

  }

  return in_RAX;

}




