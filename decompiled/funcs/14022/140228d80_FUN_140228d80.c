// Address: 0x140228d80
// Ghidra name: FUN_140228d80
// ============ 0x140228d80 FUN_140228d80 (size=193) ============


undefined1 FUN_140228d80(longlong param_1,longlong param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  undefined8 uVar3;

  char cVar4;

  undefined1 uVar5;

  longlong lVar6;

  

  lVar1 = *(longlong *)(param_2 + 0x188);

  uVar2 = FUN_14016c700();

  uVar3 = FUN_14016c6d0();

  if (*(longlong *)(param_1 + 0x690) == 0) {

    cVar4 = FUN_1402194f0(param_1,0,0,*(undefined4 *)(param_1 + 0x40c));

    if (cVar4 == '\0') {

      FUN_14021a5f0(param_1);

      return 0;

    }

    *(undefined4 *)(param_1 + 0x410) = 1;

  }

  lVar6 = FUN_140218c30(param_1,param_2,*(undefined8 *)(lVar1 + 8));

  *(longlong *)(lVar1 + 200) = lVar6;

  if (lVar6 == 0) {

    uVar5 = FUN_14012e850("Could not create GLES window surface");

  }

  else {

    uVar5 = FUN_140228d60(param_1,uVar2,uVar3);

  }

  return uVar5;

}




