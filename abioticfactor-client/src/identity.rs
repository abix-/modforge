use std::io::{self, ErrorKind};
use crate::bits::Writer;

/// A bot's distinct network identifier. Encoding this does not authenticate an
/// EOS account; servers requiring online authentication can still reject it.
pub struct PlayerId {
    product: String,
}

impl PlayerId {
    pub fn new(product: &str) -> io::Result<Self> {
        if product.len() != 32 || !product.bytes().all(|byte| byte.is_ascii_hexdigit())
            || product.bytes().all(|byte| byte == b'0') {
            return Err(io::Error::new(ErrorKind::InvalidInput, "bot identifier must contain 32 nonzero hex digits"));
        }
        Ok(Self { product: product.to_ascii_lowercase() })
    }

    pub(crate) fn connection_id(&self) -> String {
        // No base-platform or Epic account ID. The EOS decoder accepts an empty
        // left side and a 32-character product ID after '|'.
        format!("|{}", self.product)
    }

    pub(crate) fn write(&self, writer: &mut Writer) {
        writer.put(31 << 3, 8); // custom subsystem name; unencoded FString identity
        writer.string("EOSPlus");
        writer.string(&self.connection_id());
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::bits::Reader;

    #[test]
    fn identity_has_explicit_subsystem_and_nonempty_product_id() {
        let id = PlayerId::new("6D6F64666F7267654149506C61796572").unwrap();
        let mut writer = Writer::default();
        id.write(&mut writer);
        let bytes = writer.finish();
        assert_eq!(bytes[0], 0xf8);
        let mut reader = Reader::packet(&bytes).unwrap();
        assert_eq!(reader.get(8).unwrap(), 0xf8);
        assert_eq!(reader.string().unwrap(), "EOSPlus");
        assert_eq!(reader.string().unwrap(), "|6d6f64666f7267654149506c61796572");
        assert_eq!(reader.remaining(), 0);
        for bad in ["", "AIPlayer", "00000000000000000000000000000000", "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"] {
            assert!(PlayerId::new(bad).is_err());
        }
    }
}
