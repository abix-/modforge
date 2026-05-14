// Address: 0x140208a20
// Ghidra name: FUN_140208a20
// ============ 0x140208a20 FUN_140208a20 (size=132) ============


void FUN_140208a20(void)



{

  longlong lVar1;

  char cVar2;

  

  _guard_check_icall();

  cVar2 = FUN_1402086c0();

  lVar1 = DAT_1403fd198;

  if (cVar2 != '\0') {

    for (; lVar1 != 0; lVar1 = *(longlong *)(lVar1 + 0xb8)) {

      if (((*(longlong *)(lVar1 + 0xa0) == 0) && (*(longlong *)(lVar1 + 0x68) != 0)) &&

         (cVar2 = FUN_140179b50(*(undefined8 *)(lVar1 + 0x78)), cVar2 != '\0')) {

        *(undefined1 *)(lVar1 + 0x99) = 1;

        (**(code **)(*(longlong *)(lVar1 + 0x68) + 0x48))(lVar1);

        *(undefined1 *)(lVar1 + 0x99) = 0;

        FUN_140179b60(*(undefined8 *)(lVar1 + 0x78));

      }

    }

    FUN_140207ad0();

    return;

  }

  return;

}




