// Address: 0x140149000
// Ghidra name: FUN_140149000
// ============ 0x140149000 FUN_140149000 (size=63) ============


void FUN_140149000(longlong param_1,longlong param_2)



{

  longlong lVar1;

  longlong lVar2;

  longlong lVar3;

  

  lVar2 = *(longlong *)(param_1 + 0xd8);

  if (lVar2 != 0) {

    lVar3 = 0;

    do {

      lVar1 = lVar2;

      lVar2 = lVar1;

      if (*(ulonglong *)(param_2 + 0x28) < *(ulonglong *)(lVar1 + 0x28)) break;

      lVar2 = *(longlong *)(lVar1 + 0x38);

      lVar3 = lVar1;

    } while (lVar2 != 0);

    if (lVar3 != 0) {

      *(longlong *)(lVar3 + 0x38) = param_2;

      *(longlong *)(param_2 + 0x38) = lVar2;

      return;

    }

  }

  *(longlong *)(param_1 + 0xd8) = param_2;

  *(longlong *)(param_2 + 0x38) = lVar2;

  return;

}




