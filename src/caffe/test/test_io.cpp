
#include <string>

#include "gtest/gtest.h"

#include "caffe/common.hpp"
#include "caffe/util/io.hpp"

#include "caffe/test/test_caffe_main.hpp"

namespace caffe {

class IOTest : public ::testing::Test {};

bool ReadImageToDatumReference(const string& filename, const int label,
    const int height, const int width, const bool is_color, Datum* datum) {
  return true;
}

TEST_F(IOTest, TestReadImageToDatum) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  ReadImageToDatum(filename, 0, &datum);
  EXPECT_EQ(datum.channels(), 3);
  EXPECT_EQ(datum.height(), 360);
  EXPECT_EQ(datum.width(), 480);
}

TEST_F(IOTest, TestReadImageToDatumReference) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum, datum_ref;
  ReadImageToDatum(filename, 0, 0, 0, true, &datum);
  ReadImageToDatumReference(filename, 0, 0, 0, true, &datum_ref);
  EXPECT_EQ(datum.channels(), datum_ref.channels());
  EXPECT_EQ(datum.height(), datum_ref.height());
  EXPECT_EQ(datum.width(), datum_ref.width());
  EXPECT_EQ(datum.data().size(), datum_ref.data().size());

  const string& data = datum.data();
  const string& data_ref = datum.data();

  for (int i = 0; i < datum.data().size(); ++i) {
    EXPECT_TRUE(data[i] == data_ref[i]);
  }
}


TEST_F(IOTest, TestReadImageToDatumReferenceResized) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum, datum_ref;
  ReadImageToDatum(filename, 0, 100, 200, true, &datum);
  ReadImageToDatumReference(filename, 0, 100, 200, true, &datum_ref);
  EXPECT_EQ(datum.channels(), datum_ref.channels());
  EXPECT_EQ(datum.height(), datum_ref.height());
  EXPECT_EQ(datum.width(), datum_ref.width());
  EXPECT_EQ(datum.data().size(), datum_ref.data().size());

  const string& data = datum.data();
  const string& data_ref = datum.data();

  for (int i = 0; i < datum.data().size(); ++i) {
    EXPECT_TRUE(data[i] == data_ref[i]);
  }
}

TEST_F(IOTest, TestReadImageToDatumContent) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
}

TEST_F(IOTest, TestReadImageToDatumContentGray) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  const bool is_color = false;
}

TEST_F(IOTest, TestReadImageToDatumResized) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  ReadImageToDatum(filename, 0, 100, 200, &datum);
  EXPECT_EQ(datum.channels(), 3);
  EXPECT_EQ(datum.height(), 100);
  EXPECT_EQ(datum.width(), 200);
}


TEST_F(IOTest, TestReadImageToDatumResizedSquare) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  ReadImageToDatum(filename, 0, 256, 256, &datum);
  EXPECT_EQ(datum.channels(), 3);
  EXPECT_EQ(datum.height(), 256);
  EXPECT_EQ(datum.width(), 256);
}

TEST_F(IOTest, TestReadImageToDatumGray) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  const bool is_color = false;
  ReadImageToDatum(filename, 0, is_color, &datum);
  EXPECT_EQ(datum.channels(), 1);
  EXPECT_EQ(datum.height(), 360);
  EXPECT_EQ(datum.width(), 480);
}

TEST_F(IOTest, TestReadImageToDatumResizedGray) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  const bool is_color = false;
  ReadImageToDatum(filename, 0, 256, 256, is_color, &datum);
  EXPECT_EQ(datum.channels(), 1);
  EXPECT_EQ(datum.height(), 256);
  EXPECT_EQ(datum.width(), 256);
}

TEST_F(IOTest, TestReadImageToCVMat) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
}

TEST_F(IOTest, TestReadImageToCVMatResized) {
}

TEST_F(IOTest, TestReadImageToCVMatResizedSquare) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
}

TEST_F(IOTest, TestReadImageToCVMatGray) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  const bool is_color = false;
}

TEST_F(IOTest, TestReadImageToCVMatResizedGray) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  const bool is_color = false;
}

TEST_F(IOTest, TestCVMatToDatum) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
}

TEST_F(IOTest, TestCVMatToDatumContent) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
}

TEST_F(IOTest, TestCVMatToDatumReference) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
}

TEST_F(IOTest, TestReadFileToDatum) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  EXPECT_TRUE(ReadFileToDatum(filename, &datum));
  EXPECT_TRUE(datum.encoded());
  EXPECT_EQ(datum.label(), -1);
  EXPECT_EQ(datum.data().size(), 140391);
}

TEST_F(IOTest, TestDecodeDatum) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  EXPECT_TRUE(ReadFileToDatum(filename, &datum));
  EXPECT_TRUE(DecodeDatum(&datum, true));
  EXPECT_FALSE(DecodeDatum(&datum, true));
  Datum datum_ref;
  ReadImageToDatumReference(filename, 0, 0, 0, true, &datum_ref);
  EXPECT_EQ(datum.channels(), datum_ref.channels());
  EXPECT_EQ(datum.height(), datum_ref.height());
  EXPECT_EQ(datum.width(), datum_ref.width());
  EXPECT_EQ(datum.data().size(), datum_ref.data().size());

  const string& data = datum.data();
  const string& data_ref = datum_ref.data();
  for (int i = 0; i < datum.data().size(); ++i) {
    EXPECT_TRUE(data[i] == data_ref[i]);
  }
}

TEST_F(IOTest, TestDecodeDatumToCVMat) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  EXPECT_TRUE(ReadFileToDatum(filename, &datum));
}

TEST_F(IOTest, TestDecodeDatumToCVMatContent) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
}

TEST_F(IOTest, TestDecodeDatumNative) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  EXPECT_TRUE(ReadFileToDatum(filename, &datum));
  EXPECT_TRUE(DecodeDatumNative(&datum));
  EXPECT_FALSE(DecodeDatumNative(&datum));
  Datum datum_ref;
  ReadImageToDatumReference(filename, 0, 0, 0, true, &datum_ref);
  EXPECT_EQ(datum.channels(), datum_ref.channels());
  EXPECT_EQ(datum.height(), datum_ref.height());
  EXPECT_EQ(datum.width(), datum_ref.width());
  EXPECT_EQ(datum.data().size(), datum_ref.data().size());

  const string& data = datum.data();
  const string& data_ref = datum_ref.data();
  for (int i = 0; i < datum.data().size(); ++i) {
    EXPECT_TRUE(data[i] == data_ref[i]);
  }
}

TEST_F(IOTest, TestDecodeDatumToCVMatNative) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;
  EXPECT_TRUE(ReadFileToDatum(filename, &datum));
}

TEST_F(IOTest, TestDecodeDatumNativeGray) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat_gray.jpg";
  Datum datum;
  EXPECT_TRUE(ReadFileToDatum(filename, &datum));
  EXPECT_TRUE(DecodeDatumNative(&datum));
  EXPECT_FALSE(DecodeDatumNative(&datum));
  Datum datum_ref;
  ReadImageToDatumReference(filename, 0, 0, 0, false, &datum_ref);
  EXPECT_EQ(datum.channels(), datum_ref.channels());
  EXPECT_EQ(datum.height(), datum_ref.height());
  EXPECT_EQ(datum.width(), datum_ref.width());
  EXPECT_EQ(datum.data().size(), datum_ref.data().size());

  const string& data = datum.data();
  const string& data_ref = datum_ref.data();
  for (int i = 0; i < datum.data().size(); ++i) {
    EXPECT_TRUE(data[i] == data_ref[i]);
  }
}

TEST_F(IOTest, TestDecodeDatumToCVMatNativeGray) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat_gray.jpg";
  Datum datum;
}

TEST_F(IOTest, TestDecodeDatumToCVMatContentNative) {
  string filename = EXAMPLES_SOURCE_DIR "images/cat.jpg";
  Datum datum;

}

}  // namespace caffe
