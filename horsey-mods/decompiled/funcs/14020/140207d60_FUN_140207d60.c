// Address: 0x140207d60
// Ghidra name: FUN_140207d60
// ============ 0x140207d60 FUN_140207d60 (size=110) ============


undefined4 FUN_140207d60(void *param_1)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  

  uVar3 = 1;

  FUN_140159d30();

  lVar1 = DAT_1403fd198;

  do {

    if (lVar1 == 0) {

LAB_140207db7:

      FUN_14015bb10();

      return uVar3;

    }

    iVar2 = memcmp(param_1,(void *)(lVar1 + 0x30),0x10);

    if (iVar2 == 0) {

      uVar3 = *(undefined4 *)(lVar1 + 0x5c);

      goto LAB_140207db7;

    }

    lVar1 = *(longlong *)(lVar1 + 0xb8);

  } while( true );

}




