// Address: 0x1401529c0
// Ghidra name: FUN_1401529c0
// ============ 0x1401529c0 FUN_1401529c0 (size=1352) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8

FUN_1401529c0(longlong param_1,longlong param_2,longlong param_3,float *param_4,double param_5,

             undefined8 *param_6,uint param_7)



{

  undefined4 uVar1;

  undefined4 uVar2;

  char cVar3;

  undefined8 uVar4;

  char *pcVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  undefined8 in_stack_fffffffffffffe80;

  uint uVar16;

  undefined8 in_stack_fffffffffffffe88;

  undefined4 uVar17;

  undefined8 local_120;

  undefined8 local_118;

  float local_110;

  float local_10c;

  float local_108 [4];

  float local_f8;

  float local_f4;

  float local_f0;

  float local_ec;

  float local_e8;

  float local_e4;

  float local_e0;

  float local_dc;

  float local_d8;

  float local_d4;

  float local_d0;

  float local_cc;

  float local_c8;

  float local_c4;

  float local_c0;

  float local_bc;

  

  uVar16 = (uint)((ulonglong)in_stack_fffffffffffffe80 >> 0x20);

  uVar17 = (undefined4)((ulonglong)in_stack_fffffffffffffe88 >> 0x20);

  if ((param_7 == 0) && ((double)(int)(param_5 / _DAT_140333090) == param_5 / _DAT_140333090)) {

    uVar4 = FUN_140153570();

    return uVar4;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar3 = FUN_1401aa7c0(param_1,2), cVar3 == '\0')))) {

    pcVar5 = "renderer";

  }

  else {

    if (*(char *)(param_1 + 0x2d8) != '\0') {

      FUN_14012e850("Renderer\'s window has been destroyed, can\'t use further");

      return 0;

    }

    if ((param_2 != 0) &&

       ((DAT_1403e3d60 == '\0' || (cVar3 = FUN_1401aa7c0(param_2,3), cVar3 != '\0')))) {

      if (param_1 != *(longlong *)(param_2 + 0x10)) {

        uVar4 = FUN_14012e850("Texture was not created with this renderer");

        return uVar4;

      }

      if ((*(longlong *)(param_1 + 0x50) == 0) && (*(longlong *)(param_1 + 0x58) == 0)) {

        uVar4 = FUN_14012e850("Renderer does not support RenderCopyEx");

        return uVar4;

      }

      local_118 = 0;

      local_110 = (float)*(int *)(param_2 + 4);

      local_10c = (float)*(int *)(param_2 + 8);

      if ((param_3 != 0) && (cVar3 = FUN_140185680(param_3,&local_118,&local_118), cVar3 == '\0')) {

        return 1;

      }

      if (param_4 == (float *)0x0) {

        FUN_14014a2f0(param_1,local_108);

        param_4 = local_108;

      }

      cVar3 = FUN_140156f30(param_2);

      if (cVar3 == '\0') {

        return 0;

      }

      if (*(longlong *)(param_2 + 0xf8) != 0) {

        param_2 = *(longlong *)(param_2 + 0xf8);

      }

      if (param_6 == (undefined8 *)0x0) {

        local_120 = CONCAT44(param_4[3] * DAT_14039ca34,param_4[2] * DAT_14039ca34);

      }

      else {

        local_120 = *param_6;

      }

      *(undefined4 *)(param_2 + 0x130) = *(undefined4 *)(param_1 + 600);

      uVar1 = *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x90);

      uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x138) + 0x94);

      if (*(longlong *)(param_1 + 0x50) != 0) {

        uVar4 = FUN_14014a610(param_1,param_2,&local_118,param_4,param_5,&local_120,

                              CONCAT44(uVar17,param_7),uVar1,uVar2);

        return uVar4;

      }

      fVar6 = (float)thunk_FUN_1402cdc50();

      fVar7 = (float)thunk_FUN_1402cfda0();

      fVar13 = *param_4;

      fVar14 = param_4[1];

      local_c8 = fVar13 + (float)local_120;

      local_bc = fVar14 + local_120._4_4_;

      local_e4 = (local_10c + local_118._4_4_) / (float)*(int *)(param_2 + 8);

      local_f8 = (float)local_118 / (float)*(int *)(param_2 + 4);

      local_f4 = local_118._4_4_ / (float)*(int *)(param_2 + 8);

      local_f0 = (local_110 + (float)local_118) / (float)*(int *)(param_2 + 4);

      fVar12 = fVar13 + param_4[2];

      if ((param_7 & 1) != 0) {

        fVar12 = fVar13;

        fVar13 = fVar13 + param_4[2];

      }

      fVar11 = fVar14 + param_4[3];

      if ((param_7 & 2) != 0) {

        fVar11 = fVar14;

        fVar14 = fVar14 + param_4[3];

      }

      fVar8 = (fVar14 - local_bc) * fVar6;

      fVar10 = (fVar12 - local_c8) * fVar6;

      fVar9 = (fVar11 - local_bc) * fVar6;

      fVar6 = (fVar13 - local_c8) * fVar6;

      fVar14 = (fVar14 - local_bc) * fVar7;

      fVar15 = (fVar13 - local_c8) * fVar7;

      fVar13 = (fVar12 - local_c8) * fVar7;

      fVar7 = (fVar11 - local_bc) * fVar7;

      local_d8 = (fVar15 - fVar8) + local_c8;

      local_c0 = (fVar15 - fVar9) + local_c8;

      local_d4 = fVar14 + fVar6 + local_bc;

      local_cc = fVar14 + fVar10 + local_bc;

      local_d0 = (fVar13 - fVar8) + local_c8;

      local_c8 = (fVar13 - fVar9) + local_c8;

      local_c4 = fVar7 + fVar10 + local_bc;

      local_bc = fVar7 + fVar6 + local_bc;

      local_ec = local_f4;

      local_e8 = local_f0;

      local_e0 = local_f8;

      local_dc = local_e4;

      uVar4 = FUN_14014ac90(param_1,param_2,&local_d8,8,param_2 + 0x30,(ulonglong)uVar16 << 0x20,

                            &local_f8,8,4,&DAT_1403325d0,6,4,uVar1,uVar2,1,1);

      return uVar4;

    }

    pcVar5 = "texture";

  }

  FUN_14012e850("Parameter \'%s\' is invalid",pcVar5);

  return 0;

}




