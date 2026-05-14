// Address: 0x14013ad50
// Ghidra name: FUN_14013ad50
// ============ 0x14013ad50 FUN_14013ad50 (size=157) ============


void FUN_14013ad50(int *param_1)



{

  int iVar1;

  char local_108 [264];

  

  if ((param_1 != (int *)0x0) &&

     ((1 < DAT_1403fbed0 ||

      (((((iVar1 = *param_1, iVar1 != 0x400 && (iVar1 != 0x702)) && (1 < iVar1 - 0x1306U)) &&

        (iVar1 != 0x711)) &&

       (((10 < iVar1 - 0x650U || ((0x681U >> (iVar1 - 0x650U & 0x1f) & 1) == 0)) &&

        ((iVar1 != 0x600 && ((iVar1 != 0x608 && (iVar1 != 0x1200)))))))))))) {

    FUN_1401396c0(param_1,local_108,0x100);

    if (local_108[0] != '\0') {

      FUN_14012e310("SDL EVENT: %s",local_108);

    }

  }

  return;

}




