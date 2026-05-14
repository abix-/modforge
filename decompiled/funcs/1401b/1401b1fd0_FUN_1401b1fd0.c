// Address: 0x1401b1fd0
// Ghidra name: FUN_1401b1fd0
// ============ 0x1401b1fd0 FUN_1401b1fd0 (size=652) ============


void FUN_1401b1fd0(longlong param_1,int *param_2)



{

  undefined8 *puVar1;

  undefined8 *puVar2;

  longlong lVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  longlong lVar9;

  uint uVar10;

  undefined4 local_88;

  int local_84;

  uint local_80;

  undefined4 local_7c;

  undefined8 local_78;

  uint local_70;

  uint local_6c;

  uint local_68;

  int local_64;

  undefined4 local_60;

  uint local_5c;

  uint local_58;

  undefined4 local_54;

  undefined8 local_50;

  uint local_48;

  uint local_44;

  uint local_40;

  int local_3c;

  

  lVar3 = *(longlong *)(param_1 + 0x110);

  FUN_14017caa0(*(undefined8 *)(lVar3 + 0x918));

  uVar5 = 0;

  if (param_2[5] != 0) {

    uVar8 = param_2[6];

    do {

      uVar10 = 1;

      if (1 < uVar8) {

        do {

          iVar7 = uVar10 - 1;

          uVar8 = 0;

          uVar6 = uVar5;

          if (*param_2 == 2) {

            uVar6 = 0;

            uVar8 = uVar5;

          }

          lVar9 = *(longlong *)(*(longlong *)(param_2 + 10) + 0x48);

          uVar4 = FUN_1401bb2e0(iVar7,uVar6);

          puVar1 = (undefined8 *)(lVar9 + (ulonglong)uVar4 * 0x28);

          uVar4 = FUN_1401bb2e0(uVar10,uVar6);

          puVar2 = (undefined8 *)(lVar9 + (ulonglong)uVar4 * 0x28);

          FUN_1401bd590(lVar3,param_1,1,puVar1);

          FUN_1401bd590(lVar3,param_1,2);

          local_6c = (uint)param_2[3] >> ((byte)iVar7 & 0x1f);

          local_68 = (uint)param_2[4] >> ((byte)iVar7 & 0x1f);

          local_64 = uVar8 + 1;

          local_44 = (uint)param_2[3] >> ((byte)uVar10 & 0x1f);

          local_40 = (uint)param_2[4] >> ((byte)uVar10 & 0x1f);

          local_78 = 0;

          local_50 = 0;

          local_88 = 1;

          local_7c = 1;

          local_60 = 1;

          local_54 = 1;

          local_84 = iVar7;

          local_80 = uVar6;

          local_70 = uVar8;

          local_5c = uVar10;

          local_58 = uVar6;

          local_48 = uVar8;

          local_3c = local_64;

          (**(code **)(lVar3 + 0xa40))

                    (*(undefined8 *)(param_1 + 0x118),

                     *(undefined8 *)(*(longlong *)(param_2 + 10) + 0x18),6,

                     *(undefined8 *)(*(longlong *)(param_2 + 10) + 0x18),7,1,&local_88,1);

          FUN_1401bd5f0(lVar3,param_1,1,puVar1);

          FUN_1401bd5f0(lVar3,param_1,2,puVar2);

          FUN_1401bdb50(param_1,*puVar1);

          FUN_1401bdb50(param_1,*puVar2);

          FUN_1401bdc00(param_1,*puVar1);

          FUN_1401bdc00(param_1,*puVar2);

          uVar8 = param_2[6];

          uVar10 = uVar10 + 1;

        } while (uVar10 < uVar8);

      }

      uVar5 = uVar5 + 1;

    } while (uVar5 < (uint)param_2[5]);

  }

  FUN_14017cae0(*(undefined8 *)(lVar3 + 0x918));

  return;

}




