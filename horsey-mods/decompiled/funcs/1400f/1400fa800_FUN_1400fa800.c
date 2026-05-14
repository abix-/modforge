// Address: 0x1400fa800
// Ghidra name: FUN_1400fa800
// ============ 0x1400fa800 FUN_1400fa800 (size=261) ============


undefined8 FUN_1400fa800(longlong param_1)



{

  char cVar1;

  longlong *plVar2;

  longlong lVar3;

  longlong *plVar4;

  float fVar5;

  float fVar6;

  

  fVar6 = *(float *)(param_1 + 0x118) * DAT_14039ca34;

  fVar5 = *(float *)(param_1 + 0x254) * DAT_14039ca34;

  *(float *)(param_1 + 0x110) =

       *(float *)(param_1 + 0x11c) * DAT_14039ca34 - *(float *)(param_1 + 600) * DAT_14039ca34;

  *(float *)(param_1 + 0x10c) = fVar6 - fVar5;

  plVar2 = *(longlong **)(param_1 + 0x138);

  for (plVar4 = *(longlong **)(param_1 + 0x130); plVar4 != plVar2; plVar4 = plVar4 + 1) {

    FUN_1400b6610(*plVar4,*plVar4 + 0x1d4);

  }

  FUN_1400ce540(param_1,0,0);

  cVar1 = *(char *)(*(longlong *)(DAT_1403fb0d8 + 0x300) + 0xac);

  lVar3 = 0;

  *(char *)(param_1 + 0x260) = cVar1;

  if (cVar1 != '\0') {

    lVar3 = *(longlong *)(param_1 + 0x98);

    *(undefined8 *)(lVar3 + 0x19338) = DAT_1403ffbe8;

  }

  *(int *)(param_1 + 0x25c) = *(int *)(param_1 + 0x25c) + 1;

  *(undefined4 *)(param_1 + 0x250) = 0;

  *(undefined1 *)(param_1 + 0x263) = 1;

  return CONCAT71((int7)((ulonglong)lVar3 >> 8),1);

}




