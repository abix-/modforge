// Address: 0x1401de5a0
// Ghidra name: FUN_1401de5a0
// ============ 0x1401de5a0 FUN_1401de5a0 (size=462) ============


undefined8 FUN_1401de5a0(longlong param_1,int *param_2)



{

  longlong lVar1;

  int iVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  longlong *plVar5;

  longlong *local_res8;

  undefined8 in_stack_ffffffffffffff98;

  undefined4 uVar6;

  longlong **pplVar7;

  int local_48;

  int local_44;

  int local_40;

  int local_3c;

  undefined4 local_38 [2];

  undefined8 local_30;

  undefined4 local_28 [6];

  undefined4 local_10;

  undefined4 local_c;

  

  uVar6 = (undefined4)((ulonglong)in_stack_ffffffffffffff98 >> 0x20);

  lVar1 = *(longlong *)(param_1 + 0x2e0);

  plVar5 = *(longlong **)(lVar1 + 0x90);

  if (plVar5 == (longlong *)0x0) {

    plVar5 = *(longlong **)(lVar1 + 0x88);

  }

  iVar2 = (**(code **)(*plVar5 + 0x60))(plVar5,local_28);

  if (iVar2 < 0) {

    FUN_1401df290("GetDesc()",iVar2);

    uVar4 = 0;

  }

  else {

    pplVar7 = &local_res8;

    iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x120))

                      (*(longlong **)(lVar1 + 0x10),local_10,local_c,local_28[0],CONCAT44(uVar6,2),

                       pplVar7,0);

    uVar6 = (undefined4)((ulonglong)pplVar7 >> 0x20);

    if (iVar2 < 0) {

      FUN_1401df290("CreateOffscreenPlainSurface()",iVar2);

      uVar4 = 0;

    }

    else {

      iVar2 = (**(code **)(**(longlong **)(lVar1 + 0x10) + 0x100))

                        (*(longlong **)(lVar1 + 0x10),plVar5,local_res8);

      if (iVar2 < 0) {

        (**(code **)(*local_res8 + 0x10))();

        FUN_1401df290("GetRenderTargetData()",iVar2);

        uVar4 = 0;

      }

      else {

        local_48 = *param_2;

        local_40 = local_48 + param_2[2];

        local_44 = param_2[1];

        local_3c = local_44 + param_2[3];

        iVar2 = (**(code **)(*local_res8 + 0x68))(local_res8,local_38,&local_48,0x10);

        if (iVar2 < 0) {

          (**(code **)(*local_res8 + 0x10))();

          FUN_1401df290("LockRect()",iVar2);

          uVar4 = 0;

        }

        else {

          uVar3 = FUN_1401dcdc0(local_28[0]);

          uVar4 = FUN_1401460c0(param_2[2],param_2[3],uVar3,0x120005a0,local_30,

                                CONCAT44(uVar6,local_38[0]));

          (**(code **)(*local_res8 + 0x70))();

          (**(code **)(*local_res8 + 0x10))();

        }

      }

    }

  }

  return uVar4;

}




