// Address: 0x140214a40
// Ghidra name: FUN_140214a40
// ============ 0x140214a40 FUN_140214a40 (size=198) ============


undefined1 FUN_140214a40(void)



{

  longlong local_18;

  longlong local_10;

  

  local_18 = 0;

  local_10 = FUN_14017cda0(0);

  if (local_10 != 0) {

    FUN_140139020(&DAT_1403fdad0,0);

    FUN_140139010(&DAT_1403fdae8,0);

    DAT_1403fdac8 = FUN_140163490(FUN_140214b10,"SDLWASAPIMgmt",0x40000,&local_18);

    if (DAT_1403fdac8 != 0) {

      FUN_140163d70(local_10);

      FUN_14017ce80(local_10);

      if (local_18 == 0) {

        return 1;

      }

      FUN_140163d80(DAT_1403fdac8,0);

      DAT_1403fdac8 = 0;

      FUN_14012e850(&DAT_14039bf30,local_18);

      FUN_1401841e0(local_18);

    }

  }

  return 0;

}




