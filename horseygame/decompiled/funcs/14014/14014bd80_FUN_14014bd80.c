// Address: 0x14014bd80
// Ghidra name: FUN_14014bd80
// ============ 0x14014bd80 FUN_14014bd80 (size=492) ============


longlong * FUN_14014bd80(longlong param_1,longlong *param_2)



{

  char cVar1;

  longlong lVar2;

  longlong *plVar3;

  

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,2), cVar1 == '\0')))) {

    FUN_14012e850("Parameter \'%s\' is invalid","renderer");

    return (longlong *)0x0;

  }

  if (*(char *)(param_1 + 0x2d8) != '\0') {

    FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

    return (longlong *)0x0;

  }

  if (param_2 == (longlong *)0x0) {

    FUN_14012e850("Parameter \'%s\' is invalid","createinfo");

    return (longlong *)0x0;

  }

  if (*param_2 == 0) {

    FUN_14012e850("A fragment_shader is required");

    return (longlong *)0x0;

  }

  lVar2 = FUN_140174d30(*(undefined4 *)(param_1 + 0x2c8),"SDL.renderer.gpu.device",0);

  if (lVar2 == 0) {

    FUN_14012e850("Renderer isn\'t associated with a GPU device");

    return (longlong *)0x0;

  }

  plVar3 = (longlong *)FUN_1401841a0(1,0x58);

  if (plVar3 == (longlong *)0x0) {

    return (longlong *)0x0;

  }

  *plVar3 = param_1;

  plVar3[2] = *param_2;

  if (0 < (int)param_2[1]) {

    lVar2 = FUN_1401841a0((longlong)(int)param_2[1],0x10);

    plVar3[4] = lVar2;

    if (lVar2 == 0) goto LAB_14014bf05;

    FUN_1402f8e20(lVar2,param_2[2],(longlong)(int)param_2[1] << 4);

    *(int *)(plVar3 + 3) = (int)param_2[1];

  }

  if (0 < (int)param_2[3]) {

    lVar2 = FUN_1401841a0((longlong)(int)param_2[3],8);

    plVar3[6] = lVar2;

    if (lVar2 == 0) goto LAB_14014bf05;

    FUN_1402f8e20(lVar2,param_2[4],(longlong)(int)param_2[3] << 3);

    *(int *)(plVar3 + 5) = (int)param_2[3];

  }

  if ((int)param_2[5] < 1) {

    return plVar3;

  }

  lVar2 = FUN_1401841a0((longlong)(int)param_2[5],8);

  plVar3[8] = lVar2;

  if (lVar2 != 0) {

    FUN_1402f8e20(lVar2,param_2[6],(longlong)(int)param_2[5] << 3);

    *(int *)(plVar3 + 7) = (int)param_2[5];

    return plVar3;

  }

LAB_14014bf05:

  FUN_14014d980(plVar3);

  return (longlong *)0x0;

}




