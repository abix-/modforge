// Address: 0x14028b9c0
// Ghidra name: FUN_14028b9c0
// ============ 0x14028b9c0 FUN_14028b9c0 (size=812) ============


void FUN_14028b9c0(int *param_1,int *param_2)



{

  byte bVar1;

  char cVar2;

  undefined1 uVar4;

  int iVar3;

  int iVar5;

  uint uVar6;

  uint uVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  int local_res8;

  undefined2 local_resc;

  undefined1 local_rese;

  

  local_res8 = param_1[7];

  local_resc = (undefined2)param_1[8];

  local_rese = *(undefined1 *)((longlong)param_1 + 0x22);

  bVar1 = (byte)local_res8;

  if ((bVar1 & 0xf) == 1) {

    uVar6 = (uint)local_res8 >> 8;

    local_res8 = CONCAT31((int3)uVar6,(bVar1 & 0xf0) + 0xc);

  }

  iVar3 = param_1[0xb];

  if (iVar3 == 1) {

    iVar3 = 1;

    if (param_1[9] != 0) {

      iVar3 = 0xc;

    }

    param_1[9] = iVar3;

    iVar8 = *param_1;

    *(char *)(param_1 + 7) = ('\x10' << ((byte)iVar8 & 0x1f)) + (char)iVar3;

  }

  else {

    if (param_2[5] == 0) {

      param_1[9] = 3;

      *(undefined4 *)((longlong)param_1 + 0x1d) = 0;

      *(char *)(param_1 + 7) = ('\x10' << ((byte)*param_1 & 0x1f)) + '\x03';

      *(undefined2 *)((longlong)param_1 + 0x21) = 0;

      goto LAB_14028ba5b;

    }

    if (param_1[9] == 3) {

      param_1[9] = 1;

      iVar8 = *param_1;

      cVar2 = ('\x10' << ((byte)iVar8 & 0x1f)) + '\x01';

    }

    else {

      param_1[9] = 0xc;

      iVar8 = *param_1;

      cVar2 = ('\x10' << ((byte)iVar8 & 0x1f)) + '\f';

    }

    *(char *)(param_1 + 7) = cVar2;

    if (iVar3 != 1) {

      if (iVar3 == 0x80) {

        iVar3 = param_2[3];

        iVar8 = param_2[4];

        uVar6 = param_2[2] - 0x8000U >> 5 & 0x7ff;

        uVar7 = param_2[1] - 0x8000U >> 5 & 0x7ff;

        iVar10 = -iVar3;

        if (-iVar3 < 0) {

          iVar10 = iVar3;

        }

        iVar9 = -iVar8;

        if (-iVar8 < 0) {

          iVar9 = iVar8;

        }

        if (iVar10 < 0x800) {

          uVar7 = 0;

        }

        else {

          iVar10 = iVar10 + -0x800;

        }

        if (iVar9 < 0x800) {

          uVar6 = 0x7ff;

        }

        else {

          iVar9 = iVar9 + -0x800;

        }

        *(undefined1 *)((longlong)param_1 + 0x1d) = 0xb;

        *(char *)((longlong)param_1 + 0x1e) = (char)(uVar7 >> 3);

        *(char *)((longlong)param_1 + 0x1f) = (char)(uVar6 >> 3);

        iVar5 = -iVar9;

        if (-iVar9 < 0) {

          iVar5 = iVar9;

        }

        iVar9 = iVar5 * 2;

        if (0xffff < iVar5 * 2) {

          iVar9 = 0xffff;

        }

        iVar5 = -iVar10;

        if (-iVar10 < 0) {

          iVar5 = iVar10;

        }

        iVar10 = iVar5 * 2;

        if (0xffff < iVar5 * 2) {

          iVar10 = 0xffff;

        }

        *(byte *)((longlong)param_1 + 0x21) =

             (((char)uVar6 * '\x02' - (char)(iVar8 >> 0x1f)) * '\b' + ((byte)uVar7 & 7)) * '\x02' -

             (char)(iVar3 >> 0x1f);

        *(byte *)(param_1 + 8) =

             ((byte)((uint)iVar9 >> 8) & 0xf0) + ((byte)((uint)iVar10 >> 8) >> 4);

        uVar4 = (undefined1)((uint)param_2[5] >> 8);

        if (0xffff < (uint)param_2[5]) {

          uVar4 = 0xff;

        }

        *(undefined1 *)((longlong)param_1 + 0x22) = uVar4;

      }

      else if (iVar3 == 0x100) {

        iVar3 = param_2[3];

        iVar8 = param_2[4];

        *(undefined1 *)((longlong)param_1 + 0x1d) = 0xc;

        iVar10 = -param_2[3];

        if (-param_2[3] < 0) {

          iVar10 = param_2[3];

        }

        *(byte *)((longlong)param_1 + 0x1f) = (byte)((uint)iVar3 >> 0x1f);

        bVar1 = (byte)((uint)(iVar10 * 2) >> 8);

        if (0xffff < iVar10 * 2) {

          bVar1 = 0xff;

        }

        *(byte *)((longlong)param_1 + 0x1e) = bVar1 >> 4;

        iVar3 = -param_2[4];

        if (-param_2[4] < 0) {

          iVar3 = param_2[4];

        }

        *(byte *)((longlong)param_1 + 0x21) = (byte)((uint)iVar8 >> 0x1f);

        bVar1 = (byte)((uint)(iVar3 * 2) >> 8);

        if (0xffff < iVar3 * 2) {

          bVar1 = 0xff;

        }

        *(byte *)(param_1 + 8) = bVar1 >> 4;

        uVar4 = (undefined1)((uint)param_2[5] >> 8);

        if (0xffff < (uint)param_2[5]) {

          uVar4 = 0xff;

        }

        *(undefined1 *)((longlong)param_1 + 0x22) = uVar4;

      }

      else if (iVar3 == 0x400) {

        iVar3 = param_2[3];

        iVar8 = param_2[4];

        *(undefined1 *)((longlong)param_1 + 0x1d) = 0xe;

        iVar10 = -param_2[3];

        if (-param_2[3] < 0) {

          iVar10 = param_2[3];

        }

        uVar4 = (undefined1)((uint)(iVar10 * 2) >> 8);

        if (0xffff < iVar10 * 2) {

          uVar4 = 0xff;

        }

        *(undefined1 *)((longlong)param_1 + 0x1e) = uVar4;

        iVar10 = -param_2[4];

        if (-param_2[4] < 0) {

          iVar10 = param_2[4];

        }

        uVar4 = (undefined1)((uint)(iVar10 * 2) >> 8);

        if (0xffff < iVar10 * 2) {

          uVar4 = 0xff;

        }

        *(undefined1 *)((longlong)param_1 + 0x1f) = uVar4;

        uVar6 = param_2[5];

        *(undefined1 *)((longlong)param_1 + 0x22) = 0;

        if (0xffff < uVar6) {

          uVar6 = 0xffff;

        }

        *(char *)(param_1 + 8) = (char)(uVar6 >> 8);

        *(char *)((longlong)param_1 + 0x21) = (char)(iVar8 >> 0x1f) * -0x10 - (char)(iVar3 >> 0x1f);

      }

      goto LAB_14028ba5b;

    }

  }

  *(undefined4 *)((longlong)param_1 + 0x1d) = 0;

  *(undefined2 *)((longlong)param_1 + 0x21) = 0;

  iVar3 = *param_2;

  iVar10 = -0x8000;

  if ((-0x8000 < iVar3) && (iVar10 = iVar3, 0x7fff < iVar3)) {

    iVar10 = 0x7fff;

  }

  *(char *)((longlong)iVar8 + 0x1e + (longlong)param_1) = (char)((uint)(iVar10 + 0x8000) >> 8);

LAB_14028ba5b:

  iVar3 = memcmp(&local_res8,param_1 + 7,7);

  if (iVar3 != 0) {

    *(undefined1 *)(param_1 + 10) = 1;

  }

  return;

}




