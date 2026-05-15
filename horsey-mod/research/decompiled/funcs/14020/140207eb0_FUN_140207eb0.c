// Address: 0x140207eb0
// Ghidra name: FUN_140207eb0
// ============ 0x140207eb0 FUN_140207eb0 (size=110) ============


undefined4 FUN_140207eb0(void *param_1)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  

  FUN_140159d30();

  lVar1 = DAT_1403fd198;

  do {

    uVar3 = 0;

    if (lVar1 == 0) {

LAB_140207f07:

      FUN_14015bb10();

      return uVar3;

    }

    iVar2 = memcmp(param_1,(void *)(lVar1 + 0x30),0x10);

    if (iVar2 == 0) {

      uVar3 = *(undefined4 *)(lVar1 + 0x58);

      goto LAB_140207f07;

    }

    lVar1 = *(longlong *)(lVar1 + 0xb8);

  } while( true );

}




