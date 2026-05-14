// Address: 0x1402102e0
// Ghidra name: FUN_1402102e0
// ============ 0x1402102e0 FUN_1402102e0 (size=445) ============


void FUN_1402102e0(undefined8 param_1,longlong *param_2,undefined8 param_3)



{

  ushort uVar1;

  ulonglong uVar2;

  char cVar3;

  byte bVar4;

  ulonglong uVar5;

  byte bVar6;

  undefined2 uVar7;

  ushort *puVar8;

  longlong *local_res10;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  

  cVar3 = (**(code **)(*param_2 + 0x38))(param_2,&local_res10);

  if (cVar3 != '\0') {

    local_48 = 0;

    uStack_40 = 0;

    local_28 = 0;

    local_38 = 0;

    uStack_30 = 0;

    uVar5 = (**(code **)(*local_res10 + 0x30))(local_res10,0x28,&local_48);

    uVar2 = local_48;

    uVar1 = (ushort)local_48;

    if (9 < uVar5) {

      bVar6 = 0;

      puVar8 = &DAT_1403e51a8;

      do {

        if (*puVar8 != 0) {

          FUN_14015ad00(param_3,param_1,bVar6,(uVar1 & *puVar8) != 0);

        }

        bVar6 = bVar6 + 1;

        puVar8 = puVar8 + 1;

      } while (bVar6 < 0xb);

      bVar4 = (byte)(uVar2 >> 8) & 1;

      bVar6 = bVar4 | 4;

      if ((uVar2 & 0x200) == 0) {

        bVar6 = bVar4;

      }

      bVar4 = bVar6 | 8;

      if ((uVar2 & 0x400) == 0) {

        bVar4 = bVar6;

      }

      bVar6 = bVar4 | 2;

      if ((uVar2 & 0x800) == 0) {

        bVar6 = bVar4;

      }

      FUN_14015ae90(param_3,param_1,0,bVar6);

      FUN_14015aab0(param_3,param_1,2,(ushort)local_48._3_1_ * 0x101 + -0x8000);

      FUN_14015ad00(param_3,param_1,10,0xcf < local_48._2_1_);

      uVar7 = 0x8000;

      if (local_48._6_1_ != '\0') {

        uVar7 = 0x7fff;

      }

      FUN_14015aab0(param_3,param_1,4,uVar7);

      FUN_14015aab0(param_3,param_1,3,*(undefined2 *)(&DAT_140350d10 + (local_48 >> 0x24 & 0xf) * 2)

                   );

    }

  }

  return;

}




