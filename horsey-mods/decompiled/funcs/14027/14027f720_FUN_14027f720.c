// Address: 0x14027f720
// Ghidra name: FUN_14027f720
// ============ 0x14027f720 FUN_14027f720 (size=384) ============


bool FUN_14027f720(longlong param_1,int param_2)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  undefined1 local_res8;

  char cStackX_9;

  undefined1 uStackX_a;

  undefined1 uStackX_b;

  undefined1 local_resc;

  byte bStackX_d;

  undefined1 local_rese;

  

  local_resc = 0;

  bStackX_d = 0;

  iVar2 = 0x28;

  if (0x27 < param_2) {

    iVar2 = param_2;

  }

  local_rese = 0;

  if (900 < iVar2) {

    iVar2 = 900;

  }

  *(short *)(*(longlong *)(param_1 + 0x70) + 0x22) = (short)iVar2;

  switch(*(ushort *)(param_1 + 0x22) - 0xc24f) {

  case 0:

  case 0x4a:

  case 0x4b:

  case 0x4c:

    uStackX_a = (undefined1)iVar2;

    uStackX_b = (undefined1)((uint)iVar2 >> 8);

    local_res8 = 0xf8;

    cStackX_9 = 0x81;

    iVar2 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

    if (iVar2 == -1) {

      return false;

    }

  default:

    return true;

  case 0x49:

    break;

  }

  local_res8 = 0xf8;

  uStackX_a = 0;

  uStackX_b = 0;

  local_resc = 0;

  bStackX_d = 0;

  iVar4 = 900;

  local_rese = 0;

  cStackX_9 = (200 < iVar2) + '\x02';

  if (iVar2 < 0xc9) {

    iVar4 = 200;

  }

  iVar3 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

  if (iVar3 == -1) {

    return false;

  }

  local_res8 = 0x81;

  cStackX_9 = 0xb;

  uStackX_a = 0;

  uStackX_b = 0;

  local_resc = 0;

  bStackX_d = 0;

  local_rese = 0;

  if ((iVar2 != 200) && (iVar2 != 900)) {

    local_resc = 0xff;

    local_rese = 0xff;

    lVar1 = (longlong)(((iVar4 - iVar2) + 1) * 0x7ff) / (longlong)iVar4;

    iVar2 = (int)lVar1;

    iVar4 = 0xfff - iVar2;

    uStackX_a = (undefined1)(iVar2 >> 4);

    bStackX_d = ((byte)iVar4 & 0xfe) << 4 | (byte)lVar1 & 0xe;

    uStackX_b = (undefined1)(iVar4 >> 4);

  }

  iVar2 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_res8,7);

  return iVar2 != -1;

}




