// Address: 0x140067270
// Ghidra name: FUN_140067270
// ============ 0x140067270 FUN_140067270 (size=174) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



byte FUN_140067270(longlong param_1,float *param_2)



{

  float fVar1;

  bool bVar2;

  byte bVar3;

  byte bVar4;

  

  fVar1 = *param_2;

  if ((*(float *)(param_1 + 0x254) < fVar1) || (fVar1 + param_2[2] <= *(float *)(param_1 + 0x254)))

  {

LAB_1400672b2:

    bVar4 = 0;

  }

  else {

    if ((*(float *)(param_1 + 600) < param_2[1]) ||

       (param_2[1] + param_2[3] <= *(float *)(param_1 + 600))) goto LAB_1400672b2;

    bVar4 = 1;

  }

  if ((DAT_1403ed958 == 0) && ((int)_DAT_1403ed968 == 0)) {

    return bVar4;

  }

  if ((fVar1 <= *(float *)(param_1 + 0xe4)) && (*(float *)(param_1 + 0xe4) < fVar1 + param_2[2])) {

    if ((param_2[1] <= *(float *)(param_1 + 0xe8)) &&

       (*(float *)(param_1 + 0xe8) < param_2[1] + param_2[3])) {

      bVar2 = true;

      bVar3 = bVar4 | 2;

      goto LAB_14006730b;

    }

  }

  bVar2 = false;

  bVar3 = bVar4;

LAB_14006730b:

  if ((((int)_DAT_1403ed968 != 0) && (bVar4 != 0)) && (bVar2)) {

    bVar3 = bVar3 | 4;

  }

  return bVar3;

}




