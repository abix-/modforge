// Address: 0x140198200
// Ghidra name: FUN_140198200
// ============ 0x140198200 FUN_140198200 (size=257) ============


longlong FUN_140198200(longlong param_1,longlong param_2)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  longlong lVar4;

  undefined1 local_res8 [8];

  

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_140314094);

    return 0;

  }

  if (param_2 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid",&DAT_1403140bc);

    return 0;

  }

  local_res8[0] = 0;

  lVar2 = FUN_140197de0(param_2,local_res8);

  if (lVar2 == 0) {

    FUN_14012e850("Unsupported file mode");

    return 0;

  }

  lVar3 = FUN_1401841a0(1,0xd0);

  if (lVar3 != 0) {

    *(undefined1 *)(lVar3 + 0xc9) = local_res8[0];

    lVar4 = FUN_140179a30();

    *(longlong *)(lVar3 + 0x30) = lVar4;

    if (lVar4 != 0) {

      cVar1 = FUN_140230830(param_1,lVar2,lVar3);

      if (cVar1 != '\0') {

        return lVar3;

      }

      FUN_140179b30(*(undefined8 *)(lVar3 + 0x30));

    }

    FUN_1401841e0(lVar3);

  }

  return 0;

}




