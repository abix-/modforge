// Address: 0x140277890
// Ghidra name: FUN_140277890
// ============ 0x140277890 FUN_140277890 (size=256) ============


undefined4 FUN_140277890(longlong param_1)



{

  byte bVar1;

  longlong lVar2;

  char cVar3;

  int iVar4;

  longlong lVar5;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  if ((0 < *(int *)(param_1 + 0x8c)) &&

     (lVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90)), lVar5 != 0)) {

    bVar1 = *(byte *)(lVar2 + 0x18);

    *(byte *)(lVar2 + 0x18) = bVar1 + 1;

    if (200 < bVar1) {

      *(undefined1 *)(lVar2 + 0x18) = 0;

      cVar3 = FUN_140277b60(*(undefined8 *)(param_1 + 0x80));

      if (cVar3 == '\0') {

        return 0;

      }

    }

    local_48 = 0;

    uStack_40 = 0;

    local_38 = 0;

    uStack_30 = 0;

    local_28 = 0;

    uStack_20 = 0;

    local_18 = 0;

    uStack_10 = 0;

    while (iVar4 = FUN_140193780(*(undefined8 *)(param_1 + 0x80),&local_48,0x40), -1 < iVar4) {

      if (iVar4 == 0x40) {

        if ((((short)local_48 == 1) && (local_48._2_1_ == '\t')) && (local_48._3_1_ == '@')) {

          FUN_140277c00(param_1,lVar5,&local_48);

        }

      }

      else if (iVar4 < 1) {

        return 1;

      }

    }

    FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

  }

  return 0;

}




