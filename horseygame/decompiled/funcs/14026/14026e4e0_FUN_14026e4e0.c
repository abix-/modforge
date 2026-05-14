// Address: 0x14026e4e0
// Ghidra name: FUN_14026e4e0
// ============ 0x14026e4e0 FUN_14026e4e0 (size=280) ============


ulonglong FUN_14026e4e0(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  ulonglong in_RAX;

  longlong lVar3;

  char local_48;

  char local_47;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  if (*(int *)(param_1 + 0x8c) < 1) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar3 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90));

  iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);

  do {

    if (iVar2 < 1) {

      if (iVar2 < 0) {

        FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

      }

      return (ulonglong)(byte)((byte)((uint)iVar2 >> 0x1f) ^ 1);

    }

    if (lVar3 != 0) {

      if (iVar2 == 7) {

        FUN_14026f7e0(lVar3,lVar1,&local_48,7);

      }

      else {

        if ((local_48 != '\x01') || (local_47 == -1)) goto LAB_14026e592;

        FUN_14026faa0(lVar3,lVar1,&local_48,iVar2);

      }

      if (*(char *)(lVar1 + 0x13) == '\0') {

        FUN_14026fe90(param_1);

        *(undefined1 *)(lVar1 + 0x13) = 1;

      }

    }

LAB_14026e592:

    iVar2 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);

  } while( true );

}




