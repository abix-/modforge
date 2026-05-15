// Address: 0x1402171e0
// Ghidra name: FUN_1402171e0
// ============ 0x1402171e0 FUN_1402171e0 (size=203) ============


undefined8 FUN_1402171e0(longlong param_1)



{

  int iVar1;

  int iVar2;

  longlong *plVar3;

  longlong lVar4;

  double extraout_XMM0_Qa;

  double dVar5;

  

  plVar3 = (longlong *)FUN_1401841a0(1,0x10);

  *(longlong **)(param_1 + 200) = plVar3;

  if (plVar3 == (longlong *)0x0) {

    return 0;

  }

  if (*(char *)(param_1 + 0x94) == '\0') {

    lVar4 = FUN_1401841f0((longlong)*(int *)(param_1 + 0x6c));

    *plVar3 = lVar4;

    plVar3 = *(longlong **)(param_1 + 200);

    if (*plVar3 == 0) {

      return 0;

    }

  }

  iVar2 = *(int *)(param_1 + 0x84) * 1000;

  iVar1 = *(int *)(param_1 + 0x68);

  *(int *)(plVar3 + 1) = iVar2 / iVar1;

  lVar4 = FUN_140142960("SDL_AUDIO_DUMMY_TIMESCALE",(longlong)iVar2 % (longlong)iVar1 & 0xffffffff);

  if ((lVar4 != 0) && (thunk_FUN_1402de5ec(lVar4), 0.0 <= extraout_XMM0_Qa)) {

    dVar5 = (double)thunk_FUN_1402e1d50((double)*(uint *)(*(longlong *)(param_1 + 200) + 8) *

                                        extraout_XMM0_Qa);

    *(int *)(*(longlong *)(param_1 + 200) + 8) = (int)(longlong)dVar5;

  }

  return 1;

}




