// Address: 0x140288730
// Ghidra name: FUN_140288730
// ============ 0x140288730 FUN_140288730 (size=190) ============


undefined * FUN_140288730(ushort *param_1)



{

  ushort uVar1;

  undefined *puVar2;

  

  uVar1 = *param_1;

  if (uVar1 < 0x41) {

    if (uVar1 != 0x40) {

      switch(uVar1) {

      case 1:

        return &DAT_140350ac0;

      case 2:

        return &DAT_140350af0;

      default:

        return (undefined *)0x0;

      case 4:

        return &DAT_140350ae0;

      case 8:

        return &DAT_140350b00;

      case 0x10:

        return &DAT_140350b10;

      case 0x20:

        return &DAT_140350b20;

      }

    }

    return &DAT_140350ad0;

  }

  if (uVar1 == 0x80) {

    return &DAT_140350b30;

  }

  if (uVar1 == 0x100) {

    return &DAT_140350b40;

  }

  if (uVar1 != 0x200) {

    if (uVar1 != 0x400) {

      puVar2 = &DAT_140350b70;

      if (uVar1 != 0x8000) {

        puVar2 = (undefined *)0x0;

      }

      return puVar2;

    }

    return &DAT_140350b60;

  }

  return &DAT_140350b50;

}




