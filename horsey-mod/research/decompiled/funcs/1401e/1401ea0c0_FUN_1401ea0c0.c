// Address: 0x1401ea0c0
// Ghidra name: FUN_1401ea0c0
// ============ 0x1401ea0c0 FUN_1401ea0c0 (size=593) ============


void FUN_1401ea0c0(longlong param_1,uint *param_2)



{

  longlong lVar1;

  longlong lVar2;

  undefined4 uVar3;

  int iVar4;

  uint uVar5;

  undefined8 local_a8;

  undefined4 local_a0;

  undefined4 local_9c;

  undefined4 local_98;

  undefined8 local_94;

  undefined8 uStack_8c;

  undefined8 local_84;

  undefined4 local_7c;

  undefined8 local_78;

  undefined8 uStack_70;

  longlong local_68;

  undefined8 uStack_60;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 local_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  undefined4 uStack_2c;

  int iStack_28;

  int iStack_24;

  undefined4 local_20;

  undefined4 uStack_1c;

  undefined4 uStack_18;

  undefined4 uStack_14;

  

  lVar1 = *(longlong *)(param_2 + 0x4e);

  lVar2 = *(longlong *)(param_1 + 0x2e0);

  if (lVar1 != 0) {

    if ((*(char *)(lVar1 + 0x50) == '\0') && (*(char *)(lVar1 + 0x98) == '\0')) {

      (**(code **)(**(longlong **)(lVar1 + 0x38) + 0x48))(*(longlong **)(lVar1 + 0x38),0,0);

      local_78 = 0;

      uStack_70 = 0;

      local_68 = 0;

      uStack_60 = 0;

      local_48 = 0;

      local_58 = 0;

      uStack_50 = 0;

      (**(code **)(**(longlong **)(lVar1 + 8) + 0x50))(*(longlong **)(lVar1 + 8),&local_78);

      iStack_28 = (int)local_58;

      iStack_24 = *(int *)(lVar1 + 0xc4);

      local_68 = (longlong)iStack_24;

      local_20 = *(undefined4 *)(lVar1 + 200);

      iVar4 = 4;

      if ((int)local_58 == 0x3d) {

        iVar4 = 1;

      }

      uStack_60 = CONCAT44(uStack_60._4_4_,local_20);

      uVar3 = FUN_1401c5ab0(iVar4 * *(int *)(lVar1 + 0xc4),0x100);

      FUN_1401ea070(lVar2,*(undefined8 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x18),0x400);

      *(undefined4 *)(lVar1 + 0x18) = 0x400;

      local_9c = 0;

      local_94 = 0;

      uStack_8c = 0;

      local_84 = 0;

      local_7c = 0;

      local_a8 = *(undefined8 *)(lVar1 + 8);

      local_a0 = 0;

      local_98 = 0;

      local_34 = 0;

      local_40 = *(undefined8 *)(lVar1 + 0x38);

      local_38 = 1;

      local_30 = 0;

      uStack_2c = 0;

      uStack_1c = 1;

      uStack_14 = 0;

      uStack_18 = uVar3;

      (**(code **)(**(longlong **)(lVar2 + 0x48) + 0x80))

                (*(longlong **)(lVar2 + 0x48),&local_a8,*(undefined4 *)(lVar1 + 0xbc),

                 *(undefined4 *)(lVar1 + 0xc0),0,&local_40,0);

      FUN_1401ea070(lVar2,*(undefined8 *)(lVar1 + 8),*(undefined4 *)(lVar1 + 0x18),0x80);

      *(undefined4 *)(lVar1 + 0x18) = 0x80;

      FUN_1401e82f0(lVar2);

      if (*(longlong **)(lVar1 + 0x38) != (longlong *)0x0) {

        (**(code **)(**(longlong **)(lVar1 + 0x38) + 0x10))();

        *(undefined8 *)(lVar1 + 0x38) = 0;

      }

    }

    else {

      uVar5 = *param_2;

      if ((uVar5 == 0) || ((uVar5 & 0xf0000000) == 0x10000000)) {

        uVar5 = uVar5 & 0xff;

      }

      else if ((((uVar5 == 0x32595559) || (uVar5 == 0x59565955)) || (uVar5 == 0x55595659)) ||

              (uVar5 == 0x30313050)) {

        uVar5 = 2;

      }

      else {

        uVar5 = 1;

      }

      FUN_1401ea3b0(param_1,param_2,(int *)(lVar1 + 0xbc),

                    (longlong)(*(int *)(lVar1 + 0xb8) * *(int *)(lVar1 + 0xc0)) +

                    (longlong)(int)(uVar5 * *(int *)(lVar1 + 0xbc)) + *(longlong *)(lVar1 + 0xb0),

                    *(int *)(lVar1 + 0xb8));

    }

  }

  return;

}




