// Address: 0x1401baa10
// Ghidra name: FUN_1401baa10
// ============ 0x1401baa10 FUN_1401baa10 (size=603) ============


longlong FUN_1401baa10(longlong param_1,longlong *param_2,uint param_3,longlong *param_4)



{

  char cVar1;

  undefined4 *puVar2;

  longlong lVar3;

  undefined8 *puVar4;

  undefined4 *puVar5;

  ulonglong uVar6;

  longlong *local_res8;

  undefined8 local_b8;

  undefined8 uStack_b0;

  undefined8 local_a8;

  undefined8 uStack_a0;

  undefined8 local_98;

  undefined8 uStack_90;

  undefined8 local_88;

  undefined8 uStack_80;

  undefined8 local_78;

  undefined8 uStack_70;

  undefined8 local_68;

  undefined8 uStack_60;

  uint local_58;

  undefined4 uStack_54;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined4 local_38;

  uint uStack_34;

  undefined4 uStack_30;

  undefined4 uStack_2c;

  undefined4 local_28;

  undefined4 uStack_24;

  undefined4 uStack_20;

  undefined4 uStack_1c;

  

  local_res8 = (longlong *)0x0;

  FUN_1402f94c0(&local_b8,0,0xa0);

  if (param_3 == 0) {

    uStack_1c = 1;

    if (param_4 == (longlong *)0x0) goto LAB_1401baad6;

    uStack_1c = *(undefined4 *)(&DAT_1403e4250 + (longlong)*(int *)(*param_4 + 0x1c) * 4);

  }

  else {

    puVar5 = (undefined4 *)((longlong)&local_b8 + 4);

    uVar6 = (ulonglong)param_3;

    puVar2 = (undefined4 *)((longlong)param_2 + 0x24);

    do {

      puVar5[-1] = *(undefined4 *)

                    (&DAT_1403e3ec0 + (longlong)*(int *)(*(longlong *)(puVar2 + -9) + 4) * 4);

      *puVar5 = puVar2[-1];

      puVar5[1] = *puVar2;

      if (*(longlong *)(puVar2 + 1) != 0) {

        (&uStack_54)[uStack_34] =

             *(undefined4 *)(&DAT_1403e3ec0 + (longlong)*(int *)(*(longlong *)(puVar2 + 1) + 4) * 4)

        ;

        uStack_34 = uStack_34 + 1;

      }

      puVar5 = puVar5 + 3;

      puVar2 = puVar2 + 0x10;

      uVar6 = uVar6 - 1;

    } while (uVar6 != 0);

    uStack_1c = *(undefined4 *)(&DAT_1403e4250 + (longlong)*(int *)(*param_2 + 0x1c) * 4);

LAB_1401baad6:

    if (param_4 == (longlong *)0x0) {

      uStack_30 = 0;

      uStack_2c = 2;

      local_28 = 1;

      uStack_24 = 2;

      uStack_20 = 1;

      goto LAB_1401bab4a;

    }

  }

  uStack_30 = *(undefined4 *)(&DAT_1403e3ec0 + (longlong)*(int *)(*param_4 + 4) * 4);

  uStack_2c = *(undefined4 *)((longlong)param_4 + 0xc);

  local_28 = (undefined4)param_4[2];

  uStack_24 = *(undefined4 *)((longlong)param_4 + 0x14);

  uStack_20 = (undefined4)param_4[3];

LAB_1401bab4a:

  local_58 = param_3;

  FUN_140179b40(*(undefined8 *)(param_1 + 0x8e8));

  cVar1 = FUN_1401aaff0(*(undefined8 *)(param_1 + 0x800),&local_b8,&local_res8);

  if (cVar1 == '\0') {

    lVar3 = FUN_1401b6eb0(param_1,param_2,param_3,param_4);

    if (lVar3 == 0) {

      FUN_140179b60(*(undefined8 *)(param_1 + 0x8e8));

      lVar3 = 0;

    }

    else {

      puVar4 = (undefined8 *)FUN_1401841f0(0xa0);

      *puVar4 = local_b8;

      puVar4[1] = uStack_b0;

      puVar4[2] = local_a8;

      puVar4[3] = uStack_a0;

      puVar4[4] = local_98;

      puVar4[5] = uStack_90;

      puVar4[6] = local_88;

      puVar4[7] = uStack_80;

      puVar4[8] = local_78;

      puVar4[9] = uStack_70;

      puVar4[10] = local_68;

      puVar4[0xb] = uStack_60;

      puVar4[0xc] = CONCAT44(uStack_54,local_58);

      puVar4[0xd] = uStack_50;

      puVar4[0xe] = local_48;

      puVar4[0xf] = uStack_40;

      *(undefined4 *)(puVar4 + 0x10) = local_38;

      *(uint *)((longlong)puVar4 + 0x84) = uStack_34;

      *(undefined4 *)(puVar4 + 0x11) = uStack_30;

      *(undefined4 *)((longlong)puVar4 + 0x8c) = uStack_2c;

      *(undefined4 *)(puVar4 + 0x12) = local_28;

      *(undefined4 *)((longlong)puVar4 + 0x94) = uStack_24;

      *(undefined4 *)(puVar4 + 0x13) = uStack_20;

      *(undefined4 *)((longlong)puVar4 + 0x9c) = uStack_1c;

      local_res8 = (longlong *)FUN_1401841f0(8);

      *local_res8 = lVar3;

      FUN_1401ab100(*(undefined8 *)(param_1 + 0x800),puVar4,local_res8,1);

      FUN_140179b60(*(undefined8 *)(param_1 + 0x8e8));

    }

  }

  else {

    FUN_140179b60(*(undefined8 *)(param_1 + 0x8e8));

    lVar3 = *local_res8;

  }

  return lVar3;

}




