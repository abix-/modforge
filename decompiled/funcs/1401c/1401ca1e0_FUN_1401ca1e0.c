// Address: 0x1401ca1e0
// Ghidra name: FUN_1401ca1e0
// ============ 0x1401ca1e0 FUN_1401ca1e0 (size=705) ============


undefined8

FUN_1401ca1e0(longlong param_1,longlong *param_2,int param_3,undefined4 param_4,undefined4 *param_5)



{

  int iVar1;

  undefined8 *puVar2;

  longlong lVar3;

  undefined8 uVar4;

  undefined8 *puVar5;

  undefined4 uVar6;

  longlong lVar7;

  longlong *local_res10;

  undefined4 local_a8;

  undefined8 local_a4;

  undefined4 local_9c;

  undefined4 local_90;

  undefined4 local_8c;

  undefined4 local_88;

  undefined4 local_80;

  undefined4 local_7c;

  undefined8 local_78;

  undefined1 local_68 [16];

  undefined4 local_58;

  undefined4 local_50;

  

  lVar7 = (longlong)param_3;

  uVar6 = *(undefined4 *)(&DAT_1403e4348 + lVar7 * 4);

  iVar1 = (**(code **)(*param_2 + 0x48))(param_2,param_4,&DAT_1403492f8,&local_res10);

  if (iVar1 < 0) {

    FUN_1401cb240(param_1,"Could not get buffer from swapchain!",iVar1);

  }

  else {

    puVar2 = (undefined8 *)FUN_1401841a0(1,0x50);

    if (puVar2 == (undefined8 *)0x0) {

      (**(code **)(*local_res10 + 0x10))();

    }

    else {

      puVar2[4] = 0;

      FUN_140139010(puVar2 + 9,0);

      *(undefined4 *)(puVar2 + 3) = 1;

      lVar3 = FUN_1401841a0(1,0x60);

      puVar2[2] = lVar3;

      if (lVar3 != 0) {

        uVar4 = FUN_1401841a0(1,0x20);

        *(undefined8 *)(lVar3 + 0x18) = uVar4;

        *(undefined8 *)(puVar2[2] + 0x28) = 0;

        *(undefined8 *)(puVar2[2] + 0x48) = 0;

        *(undefined8 **)puVar2[2] = puVar2;

        *(undefined4 *)(puVar2[2] + 0x14) = 0;

        *(undefined4 *)(puVar2[2] + 8) = 0;

        *(undefined4 *)(puVar2[2] + 0x10) = 1;

        *(undefined4 *)(puVar2[2] + 0xc) = 0;

        (**(code **)(*local_res10 + 0x50))(local_res10,local_68);

        param_5[3] = local_58;

        param_5[4] = local_50;

        param_5[1] = *(undefined4 *)(&DAT_1403e4338 + lVar7 * 4);

        param_5[5] = 1;

        *(undefined8 *)(param_5 + 6) = 1;

        *param_5 = 0;

        param_5[2] = 2;

        *(undefined8 *)(param_5 + 0x12) = 0;

        puVar5 = (undefined8 *)FUN_1401841a0(1,8);

        *(undefined8 **)(param_5 + 0xc) = puVar5;

        if (puVar5 != (undefined8 *)0x0) {

          param_5[0xe] = 1;

          param_5[0xf] = 1;

          *puVar5 = puVar2;

          *(undefined8 **)(param_5 + 10) = puVar2;

          *(undefined1 *)(param_5 + 0x10) = 0;

          *puVar2 = param_5;

          *(undefined4 *)(puVar2 + 1) = 0;

          FUN_1401c5df0(param_1,0,puVar2 + 5);

          local_90 = *(undefined4 *)(&DAT_1403e4348 + lVar7 * 4);

          local_88 = 0x1688;

          local_8c = 4;

          local_7c = 1;

          local_80 = 0;

          local_78 = 0;

          (**(code **)(**(longlong **)(param_1 + 0x70) + 0x90))

                    (*(longlong **)(param_1 + 0x70),local_res10,&local_90,puVar2[7]);

          FUN_1401c5df0(param_1,2,*(undefined8 *)(puVar2[2] + 0x18));

          local_a4 = 4;

          local_9c = 0;

          if (param_3 == 1) {

            uVar6 = 0x5b;

          }

          local_a8 = uVar6;

          (**(code **)(**(longlong **)(param_1 + 0x70) + 0xa0))

                    (*(longlong **)(param_1 + 0x70),local_res10,&local_a8,

                     *(undefined8 *)(*(longlong *)(puVar2[2] + 0x18) + 0x10));

          (**(code **)(*local_res10 + 0x10))();

          return 1;

        }

        FUN_1401841e0(puVar2[2]);

      }

      FUN_1401841e0(puVar2);

      (**(code **)(*local_res10 + 0x10))();

    }

  }

  return 0;

}




