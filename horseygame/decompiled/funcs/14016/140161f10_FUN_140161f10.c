// Address: 0x140161f10
// Ghidra name: FUN_140161f10
// ============ 0x140161f10 FUN_140161f10 (size=1297) ============


void FUN_140161f10(undefined8 param_1,longlong param_2,uint param_3,char param_4,float param_5,

                  float param_6)



{

  float *pfVar1;

  float *pfVar2;

  bool bVar3;

  char cVar4;

  int iVar5;

  longlong lVar6;

  undefined4 uVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  undefined8 in_stack_fffffffffffffef8;

  undefined8 in_stack_ffffffffffffff00;

  undefined4 uVar11;

  undefined4 local_d8 [2];

  undefined8 local_d0;

  undefined4 local_c8;

  uint local_c4;

  undefined4 local_c0;

  undefined4 local_bc;

  undefined4 local_b8;

  float local_b4;

  float local_b0;

  

  uVar7 = (undefined4)((ulonglong)in_stack_fffffffffffffef8 >> 0x20);

  uVar11 = (undefined4)((ulonglong)in_stack_ffffffffffffff00 >> 0x20);

  lVar6 = FUN_1401611a0();

  fVar9 = 0.0;

  fVar10 = 0.0;

  if ((*(longlong *)(lVar6 + 0x88) == 0) ||

     (bVar3 = true, (*(uint *)(*(longlong *)(lVar6 + 0x88) + 0x48) >> 0xf & 1) == 0)) {

    bVar3 = false;

  }

  if ((((*(char *)(lVar6 + 0xed) != '\0') && (param_3 < 0xfffffffe)) && (param_4 == '\0')) &&

     ((DAT_1403fc32d != '\0' && (param_2 != 0)))) {

    FUN_140186970(param_1,0xffffffffffffffff,1,param_2,

                  CONCAT44(uVar7,param_5 / (float)*(int *)(param_2 + 0x20)),

                  CONCAT44(uVar11,param_6 / (float)*(int *)(param_2 + 0x24)),DAT_14039ca44);

  }

  if ((*(char *)(lVar6 + 0xec) == '\0') && (param_3 == 0xffffffff)) {

    return;

  }

  if (param_4 == '\0') {

    if ((*(byte *)(lVar6 + 0x78) & 1) != 0) {

      param_5 = (float)thunk_FUN_1402e1f30();

      param_6 = (float)thunk_FUN_1402e1f30();

    }

    FUN_140160390(lVar6,param_2,&param_5,&param_6);

    if (*(char *)(lVar6 + 0xc0) == '\0') goto LAB_140162159;

    fVar9 = param_5 - *(float *)(lVar6 + 0xa0);

    fVar10 = param_6 - *(float *)(lVar6 + 0xa4);

    cVar4 = *(char *)(lVar6 + 0xc0);

  }

  else {

    if (*(char *)(lVar6 + 0xc1) == '\0') {

      if (*(char *)(lVar6 + 0xd0) != '\0') {

        param_5 = param_5 * *(float *)(lVar6 + 0xd4);

        param_6 = param_6 * *(float *)(lVar6 + 0xd4);

      }

    }

    else if (*(code **)(lVar6 + 0x68) == (code *)0x0) {

      if ((*(char *)(lVar6 + 0xe0) != '\0') && (*(code **)(lVar6 + 0x58) != (code *)0x0)) {

        (**(code **)(lVar6 + 0x58))

                  (*(undefined8 *)(lVar6 + 0x60),param_1,param_2,param_3,&param_5,&param_6);

      }

      if (*(char *)(lVar6 + 0xd8) != '\0') {

        param_5 = param_5 * *(float *)(lVar6 + 0xdc);

        param_6 = param_6 * *(float *)(lVar6 + 0xdc);

      }

    }

    else {

      (**(code **)(lVar6 + 0x68))

                (*(undefined8 *)(lVar6 + 0x70),param_1,param_2,param_3,&param_5,&param_6);

    }

    if ((*(byte *)(lVar6 + 0x78) & 1) != 0) {

      uVar7 = FUN_140190500(param_5 + *(float *)(lVar6 + 0x7c),&param_5);

      *(undefined4 *)(lVar6 + 0x7c) = uVar7;

      uVar7 = FUN_140190500(param_6 + *(float *)(lVar6 + 0x80),&param_6);

      *(undefined4 *)(lVar6 + 0x80) = uVar7;

    }

    fVar10 = param_6;

    fVar9 = param_5;

    param_5 = param_5 + *(float *)(lVar6 + 0xa0);

    param_6 = param_6 + *(float *)(lVar6 + 0xa4);

    FUN_140160390(lVar6,param_2,&param_5,&param_6);

LAB_140162159:

    cVar4 = *(char *)(lVar6 + 0xc0);

    if (cVar4 == '\0') goto LAB_140162178;

  }

  if ((fVar9 == 0.0) && (fVar10 == 0.0)) {

    return;

  }

LAB_140162178:

  if ((param_3 == 0xffffffff) && (iVar5 = FUN_1401611b0(lVar6,0xffffffff,1), iVar5 == 0)) {

    fVar9 = 0.0;

    fVar10 = 0.0;

  }

  *(float *)(lVar6 + 0x98) = fVar9 + *(float *)(lVar6 + 0x98);

  *(float *)(lVar6 + 0x9c) = fVar10 + *(float *)(lVar6 + 0x9c);

  if ((param_4 == '\0') || (cVar4 == '\0')) {

    *(float *)(lVar6 + 0x90) = param_5;

    *(float *)(lVar6 + 0x94) = param_6;

    *(undefined1 *)(lVar6 + 0xc0) = 1;

    if (param_4 == '\0') {

      *(float *)(lVar6 + 0xa0) = param_5;

      fVar8 = param_6;

    }

    else {

      *(float *)(lVar6 + 0xa0) = *(float *)(lVar6 + 0x90);

      fVar8 = *(float *)(lVar6 + 0x94);

    }

  }

  else {

    pfVar1 = (float *)(lVar6 + 0x90);

    pfVar2 = (float *)(lVar6 + 0x94);

    *pfVar1 = fVar9 + *pfVar1;

    *pfVar2 = fVar10 + *pfVar2;

    FUN_140160390(lVar6,param_2,pfVar1,pfVar2);

    *(undefined1 *)(lVar6 + 0xc0) = 1;

    *(float *)(lVar6 + 0xa0) = *pfVar1;

    fVar8 = *pfVar2;

  }

  *(float *)(lVar6 + 0xa4) = fVar8;

  *(double *)(lVar6 + 0xb0) = (double)fVar9 + *(double *)(lVar6 + 0xb0);

  *(double *)(lVar6 + 0xb8) = (double)fVar10 + *(double *)(lVar6 + 0xb8);

  if ((((*(char *)(lVar6 + 0x128) != '\0') && (*(char *)(lVar6 + 0xc1) == '\0')) &&

      (*(code **)(lVar6 + 0x20) != (code *)0x0)) && (*(longlong *)(lVar6 + 0x120) != 0)) {

    (**(code **)(lVar6 + 0x20))();

  }

  cVar4 = FUN_140139420();

  if (cVar4 != '\0') {

    if (((*(char *)(lVar6 + 0xc1) == '\0') || (*(char *)(lVar6 + 0xc6) != '\0')) &&

       (param_3 < 0xfffffffe)) {

      param_3 = 0;

    }

    if ((param_4 == '\0') && (bVar3)) {

      if (*(char *)(lVar6 + 0xc2) == '\0') {

        return;

      }

      fVar9 = 0.0;

      fVar10 = 0.0;

    }

    local_d8[0] = 0x400;

    if (*(undefined4 **)(lVar6 + 0x88) == (undefined4 *)0x0) {

      local_c8 = 0;

    }

    else {

      local_c8 = **(undefined4 **)(lVar6 + 0x88);

    }

    *(bool *)(lVar6 + 0xf0) = param_3 == 0xffffffff;

    local_d0 = param_1;

    local_c4 = param_3;

    local_c0 = FUN_1401611b0(lVar6,param_3,1);

    local_bc = *(undefined4 *)(lVar6 + 0x90);

    local_b8 = *(undefined4 *)(lVar6 + 0x94);

    local_b4 = fVar9;

    local_b0 = fVar10;

    FUN_14013b140(local_d8);

  }

  return;

}




