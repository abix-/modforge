// Address: 0x140163300
// Ghidra name: FUN_140163300
// ============ 0x140163300 FUN_140163300 (size=394) ============


longlong FUN_140163300(ulonglong param_1,undefined8 param_2,undefined8 param_3)



{

  char cVar1;

  longlong lVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined8 uVar5;

  longlong lVar6;

  

  lVar2 = FUN_140174d30(param_1,"SDL.thread.create.entry_function",0);

  lVar3 = FUN_140174e70(param_1 & 0xffffffff,"SDL.thread.create.name",0);

  uVar4 = FUN_140174c40(param_1 & 0xffffffff,"SDL.thread.create.stacksize",0);

  uVar5 = FUN_140174d30(param_1 & 0xffffffff,"SDL.thread.create.userdata",0);

  if (lVar2 == 0) {

    FUN_14012e850("Thread entry function is NULL");

    return 0;

  }

  FUN_14017e340();

  lVar6 = FUN_1401841a0(1,0x78);

  if (lVar6 == 0) {

    return 0;

  }

  *(undefined4 *)(lVar6 + 0x10) = 0xffffffff;

  FUN_140139010(lVar6 + 0x14,1);

  if (lVar3 != 0) {

    lVar3 = FUN_14012f0d0(lVar3);

    *(longlong *)(lVar6 + 0x40) = lVar3;

    if (lVar3 == 0) goto LAB_1401633ea;

  }

  lVar3 = FUN_14017cda0(0);

  *(longlong *)(lVar6 + 0x50) = lVar3;

  if (lVar3 != 0) {

    *(longlong *)(lVar6 + 0x58) = lVar2;

    *(undefined8 *)(lVar6 + 0x60) = uVar5;

    *(undefined8 *)(lVar6 + 0x48) = uVar4;

    FUN_1401aa9d0(lVar6,10,1);

    cVar1 = FUN_14017ffd0(lVar6,param_2,param_3);

    if (cVar1 == '\0') {

      FUN_1401aa9d0(lVar6,10,0);

      FUN_14017ce80(*(undefined8 *)(lVar6 + 0x50));

      FUN_1401841e0(*(undefined8 *)(lVar6 + 0x40));

      FUN_1401841e0(lVar6);

      lVar6 = 0;

    }

    FUN_140163d70(*(undefined8 *)(lVar6 + 0x50));

    FUN_14017ce80(*(undefined8 *)(lVar6 + 0x50));

    *(undefined8 *)(lVar6 + 0x50) = 0;

    return lVar6;

  }

  FUN_1401841e0(*(undefined8 *)(lVar6 + 0x40));

LAB_1401633ea:

  FUN_1401841e0(lVar6);

  return 0;

}




