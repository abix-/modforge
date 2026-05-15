// Address: 0x140287da0
// Ghidra name: FUN_140287da0
// ============ 0x140287da0 FUN_140287da0 (size=129) ============


uint FUN_140287da0(void *param_1)



{

  longlong lVar1;

  uint in_EAX;

  uint uVar2;

  longlong lVar3;

  

  lVar3 = 0;

  lVar1 = DAT_1403fdb58;

  if (DAT_1403fde60 != 0) {

    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0x490)) {

      in_EAX = memcmp((void *)(lVar1 + 0x18),param_1,0x44c);

      if (in_EAX == 0) {

        uVar2 = FUN_14021aee0(lVar3,lVar1);

        return uVar2;

      }

      lVar3 = lVar1;

    }

  }

  return in_EAX & 0xffffff00;

}




