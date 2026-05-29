#include "../header/Piquet.h"
#include "../header/SpeedRestriction.h"

#include <gtest/gtest.h>
#include <sstream>

TEST(PiquetTests, ConstructorCreatesStandardPiquet)
{
    const Piquet piquet(12, 28.37, 100.0);

    EXPECT_EQ(piquet.GetNumber(), 12);
    EXPECT_DOUBLE_EQ(piquet.GetShift(), 28.37);
    EXPECT_DOUBLE_EQ(piquet.GetLength(), 100.0);
    EXPECT_TRUE(piquet.IsStandard());
}

TEST(PiquetTests, ToStringReturnsCorrectText)
{
    const Piquet piquet(12, 28.37, 100.0);

    EXPECT_EQ(piquet.ToString(), "ПК 12+28,37");
}

TEST(PiquetTests, CompareOperatorsCompareCoordinate)
{
    const Piquet first(12, 28.37, 100.0);
    const Piquet second(13, 0.0, 100.0);

    EXPECT_TRUE(first < second);
    EXPECT_TRUE(second > first);
    EXPECT_TRUE(first <= second);
    EXPECT_TRUE(second >= first);
}

TEST(PiquetTests, EqualOperatorReturnsTrueForEqualPiquets)
{
    const Piquet first(12, 28.37, 100.0);
    const Piquet second(12, 28.37, 100.0);

    EXPECT_TRUE(first == second);
    EXPECT_FALSE(first != second);
}

TEST(SpeedRestrictionTests, ConstructorCreatesRestriction)
{
    const SpeedRestriction restriction(Piquet(12, 28.37, 100.0), Piquet(14, 10.0, 100.0), 40.0);

    EXPECT_DOUBLE_EQ(restriction.GetSpeedLimit(), 40.0);
    EXPECT_EQ(restriction.GetStart(), Piquet(12, 28.37, 100.0));
    EXPECT_EQ(restriction.GetFinish(), Piquet(14, 10.0, 100.0));
}

TEST(SpeedRestrictionTests, ToStringReturnsCorrectText)
{
    const SpeedRestriction restriction(Piquet(12, 28.37, 100.0), Piquet(14, 10.0, 100.0), 40.0);

    EXPECT_EQ(restriction.ToString(), "Ограничение скорости: от ПК 12+28,37 до ПК 14+10,00, скорость 40.00 км/ч");
}

TEST(SpeedRestrictionTests, StaticToStringReturnsCorrectText)
{
    const SpeedRestriction restriction(Piquet(12, 28.37, 100.0), Piquet(14, 10.0, 100.0), 40.0);

    EXPECT_EQ(SpeedRestriction::ToString(restriction), restriction.ToString());
}

TEST(SpeedRestrictionTests, ReadCreatesRestrictionFromStream)
{
    std::istringstream stream("12 28.37 100 14 10 100 40");

    const SpeedRestriction restriction = SpeedRestriction::Read(stream);

    EXPECT_EQ(restriction, SpeedRestriction(Piquet(12, 28.37, 100.0), Piquet(14, 10.0, 100.0), 40.0));
}
