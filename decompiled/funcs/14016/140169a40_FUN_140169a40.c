// Address: 0x140169a40
// Ghidra name: FUN_140169a40
// ============ 0x140169a40 FUN_140169a40 (size=216) ============


undefined1 FUN_140169a40(undefined1 *param_1)



{

  undefined1 uVar1;

  char cVar2;

  longlong lVar3;

  undefined8 uVar4;

  longlong lVar5;

  undefined1 *puVar6;

  

  lVar3 = FUN_14016dcf0();

  if (lVar3 == 0) {

    uVar1 = FUN_1401730c0();

    return uVar1;

  }

  puVar6 = &DAT_14039bcb9;

  if (param_1 != (undefined1 *)0x0) {

    puVar6 = param_1;

  }

  if (*(code **)(lVar3 + 0x2d8) == (code *)0x0) {

    FUN_1401841e0(*(undefined8 *)(lVar3 + 0x388));

    uVar4 = FUN_14012f0d0(puVar6);

    *(undefined8 *)(lVar3 + 0x388) = uVar4;

  }

  else {

    cVar2 = (**(code **)(lVar3 + 0x2d8))(lVar3,puVar6);

    if (cVar2 == '\0') {

      return 0;

    }

  }

  lVar5 = FUN_140169080(*(undefined8 *)(lVar3 + 0x378),*(undefined8 *)(lVar3 + 0x380),1);

  if (lVar5 == 0) {

    uVar1 = FUN_14012e850("unable to copy current mime types");

    return uVar1;

  }

  FUN_140218400(1,lVar5,*(undefined8 *)(lVar3 + 0x380));

  return 1;

}




