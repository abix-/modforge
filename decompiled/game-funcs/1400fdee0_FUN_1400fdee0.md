# `FUN_1400fdee0` @ 0x1400fdee0

**Size**: 1018 bytes
**Role**: _unclassified - needs manual reading_
**Pattern category**: `unclassified`

**Game callers** (2): [`FUN_14006e480`](14006e480_FUN_14006e480.md), [`FUN_1400fdee0`](1400fdee0_FUN_1400fdee0.md)

**Game callees** (26): [`FUN_14002cd80`](14002cd80_FUN_14002cd80.md), [`FUN_14002f0f0`](14002f0f0_FUN_14002f0f0.md), [`FUN_140030940`](140030940_FUN_140030940.md), [`FUN_1400379e0`](1400379e0_FUN_1400379e0.md), [`FUN_14003e720`](14003e720_FUN_14003e720.md), [`FUN_140057c20`](140057c20_FUN_140057c20.md), [`FUN_14005bad0`](14005bad0_FUN_14005bad0.md), [`FUN_14005bf10`](14005bf10_FUN_14005bf10.md), [`FUN_14005e310`](14005e310_FUN_14005e310.md), [`FUN_14005fad0`](14005fad0_FUN_14005fad0.md)
  ... +16 more

**Vendor callees**: 0 (SDL/CRT/etc, not shown)

## Decompiled

```c
longlong FUN_1400fdee0(undefined8 param_1,int param_2)

{

  longlong lVar1;

  longlong lVar2;

  lVar2 = 0;

  if (param_2 < 0xd) {

    lVar1 = FUN_1402c704c(0x478);

    if (lVar1 != 0) {

      lVar2 = FUN_1400db270(lVar1,param_2);

    }

  }

  else if (param_2 == 0xd) {

    lVar1 = FUN_1402c704c(1000);

    if (lVar1 != 0) {

      lVar2 = FUN_14008f6e0(lVar1);

    }

  }

  else if (param_2 == 0xe) {

    lVar1 = FUN_1402c704c(0x2d0);

    if (lVar1 != 0) {

      lVar2 = FUN_14005fad0(lVar1);

    }

  }

  else if (param_2 == 0x10) {

    lVar1 = FUN_1402c704c(0x4d8);

    if (lVar1 != 0) {

      lVar2 = FUN_140088000(lVar1);

    }

  }

  else if (param_2 == 0x11) {

    lVar1 = FUN_1402c704c(0x288);

    if (lVar1 != 0) {

      lVar2 = FUN_1400a6cb0(lVar1);

    }

  }

  else if (param_2 == 0x12) {

    lVar1 = FUN_1402c704c(0x270);

    if (lVar1 != 0) {

      lVar2 = FUN_14008de50(lVar1);

    }

  }

  else if (param_2 == 0x13) {

    lVar1 = FUN_1402c704c(0x488);

    if (lVar1 != 0) {

      lVar2 = FUN_1400bfa90(lVar1);

    }

  }

  else if (param_2 == 0x14) {

    lVar1 = FUN_1402c704c(0x310);

    if (lVar1 != 0) {

      lVar2 = FUN_14007dbf0(lVar1,0);

    }

  }

  else if (param_2 == 0x15) {

    lVar1 = FUN_1402c704c(0x2e0);

    if (lVar1 != 0) {

      lVar2 = FUN_140057c20(lVar1);

    }

  }

  else if (param_2 == 0x16) {

    lVar1 = FUN_1402c704c(0x328);

    if (lVar1 != 0) {

      lVar2 = FUN_140064590(lVar1);

    }

  }

  else if (param_2 == 0x1d) {

    lVar1 = FUN_1402c704c(0x2b0);

    if (lVar1 != 0) {

      lVar2 = FUN_14007ad10(lVar1);

    }

  }

  else if (param_2 == 0x19) {

    lVar1 = FUN_1402c704c(0x278);

    if (lVar1 != 0) {

      lVar2 = FUN_14002f0f0(lVar1);

    }

  }

  else if (param_2 == 0x18) {

    lVar1 = FUN_1402c704c(0x250);

    if (lVar1 != 0) {

      lVar2 = FUN_1401123f0(lVar1);

    }

  }

  else if (param_2 == 0x1a) {

    lVar1 = FUN_1402c704c(0x2f0);

    if (lVar1 != 0) {

      lVar2 = FUN_140069ee0(lVar1);

    }

  }

  else if (param_2 == 0x1b) {

    lVar1 = FUN_1402c704c(0x288);

    if (lVar1 != 0) {

      lVar2 = FUN_140067e60(lVar1);

    }

  }

  else if (param_2 == 0x1e) {

    lVar1 = FUN_1402c704c(0x250);

    if (lVar1 != 0) {

      lVar2 = FUN_140067850(lVar1);

    }

  }

  else if (param_2 == 0x1f) {

    lVar1 = FUN_1402c704c(0x6b8);

    if (lVar1 != 0) {

      lVar2 = FUN_140030940(lVar1);

    }

  }

  else if (param_2 == 0xf) {

    lVar1 = FUN_1402c704c(600);

    if (lVar1 != 0) {

      lVar2 = FUN_14005bf10(lVar1);

    }

  }

  else if (param_2 == 0x17) {

    lVar1 = FUN_1402c704c(0x2268);

    if (lVar1 != 0) {

      lVar2 = FUN_1400379e0(lVar1);

    }

  }

  else if (param_2 == 0x1c) {

    lVar1 = FUN_1402c704c(0x288);

    if (lVar1 != 0) {

      lVar2 = FUN_1400f4ea0(lVar1);

    }

  }

  else if (param_2 == 0x24) {

    lVar1 = FUN_1402c704c(0x250);

    if (lVar1 != 0) {

      lVar2 = FUN_14003e720(lVar1);

    }

  }

  else if (param_2 == 0x25) {

    lVar1 = FUN_1402c704c(0x288);

    if (lVar1 != 0) {

      lVar2 = FUN_14002cd80(lVar1);

    }

  }

  else if (param_2 == 0x26) {

    lVar1 = FUN_1402c704c(0x270);

    if (lVar1 != 0) {

      lVar2 = FUN_14005e310(lVar1);

    }

  }

  else {

    if (param_2 != 0x2f) {

      return 0;

    }

    lVar1 = FUN_1402c704c(600);

    if (lVar1 != 0) {

      lVar2 = FUN_14005bad0(lVar1);

    }

  }

  if (lVar2 == 0) {

    return 0;

  }

  *(int *)(lVar2 + 8) = param_2;

  return lVar2;

}
```