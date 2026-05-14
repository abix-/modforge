// Address: 0x1400d8c70
// Ghidra name: FUN_1400d8c70
// ============ 0x1400d8c70 FUN_1400d8c70 (size=139) ============


bool FUN_1400d8c70(longlong *param_1,int param_2,int param_3)



{

  bool bVar1;

  float fVar2;

  float extraout_XMM0_Da;

  

  fVar2 = (float)FUN_1400b6150(*(undefined8 *)

                                (*(longlong *)(*param_1 + 0x130) + (longlong)param_2 * 8));

  FUN_1400b6150(*(undefined8 *)(*(longlong *)(*param_1 + 0x130) + (longlong)param_3 * 8));

  if (fVar2 == extraout_XMM0_Da) {

    bVar1 = *(int *)(*(longlong *)(*(longlong *)(*param_1 + 0x130) + (longlong)param_2 * 8) + 0x1d0)

            < *(int *)(*(longlong *)(*(longlong *)(*param_1 + 0x130) + (longlong)param_3 * 8) +

                      0x1d0);

  }

  else {

    bVar1 = fVar2 < extraout_XMM0_Da;

  }

  return bVar1;

}




