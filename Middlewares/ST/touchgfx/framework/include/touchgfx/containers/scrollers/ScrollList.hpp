/******************************************************************************
* Copyright (c) 2018(-2024) STMicroelectronics.
* All rights reserved.
*
* This file is part of the TouchGFX 4.24.0 distribution.
*
* This software is licensed under terms that can be found in the LICENSE file in
* the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
*******************************************************************************/

/**
 * @file touchgfx/containers/scrollers/ScrollList.hpp
 *
 * Declares the touchgfx::ScrollList class.
 */
#ifndef TOUCHGFX_SCROLLLIST_HPP
#define TOUCHGFX_SCROLLLIST_HPP

#include <touchgfx/Callback.hpp>
#include <touchgfx/containers/scrollers/DrawableList.hpp>
#include <touchgfx/containers/scrollers/ScrollBase.hpp>
#include <touchgfx/events/ClickEvent.hpp>
#include <touchgfx/hal/Types.hpp>

namespace touchgfx
{
/**
 * A simple list of scrolling drawables. Since a long list of drawables only display a few of
 * items at any one time, the drawables are re-used to preserve resources.
 *
 * @see DrawableList
 */
class ScrollList : public ScrollBase
{
public:
    ScrollList();

    virtual void setWidth(int16_t width);

    virtual void setHeight(int16_t height);

    virtual void setDrawableSize(int16_t drawableSize, int16_t drawableMargin);

    /**
     * Setup a list of drawables and provide a function to call to update a given Drawable
     * with new contents.
     *
     * @param [in] drawableListItems      The drawables allocated.
     * @param [in] updateDrawableCallback A callback to update the contents of a specific
     *                                    drawable with a specific item.
     *
     * @see DrawableList::setDrawables
     */
    virtual void setDrawables(DrawableListItemsInterface& drawableListItems, GenericCallback<DrawableListItemsInterface*, int16_t, int16_t>& updateDrawableCallback);

    /**
     * Sets window size, i.e. the number of items that should always be visible. The default
     * value is 1. If three items are visible on the display and window size is set to three,
     * no part of the screen will be blank (unless the list contains less than three items
     * and the list is not circular).
     *
     * @param  items The number of items that should always be visible.
     *
     * @note This only applies to non-circular lists.
     */
    void setWindowSize(int16_t items);

    /**
     * Sets distance offset before and after the "visible" drawables in the ScrollList. This
     * allows the actual area where widgets are placed to have a little extra area where
     * parts of drawables can be seen. For example if the ScrollList is 200, each drawable
     * is 50 and distance before and distance after are 25, then there is room for three
     * visible drawables inside the ScrollList. When scrolling, part of the scrolled out
     * drawables can be seen before and after the three drawables. In this case 25/50 = 50%
     * of a drawable can be seen before and after the three drawables in the ScrollList.
     *
     * @param  paddingBefore The distance before the first drawable in the ScrollList.
     * @param  paddingAfter  The distance after the last drawable in the ScrollList.
     *
     * @see getPaddingBefore, getPaddingAfter
     */
    void setPadding(int16_t paddingBefore, int16_t paddingAfter);

    /**
     * Gets distance before first drawable in ScrollList.
     *
     * @return The distance before.
     *
     * @see setPadding, getPaddingAfter
     */
    int16_t getPaddingBefore() const;

    /**
     * Gets distance after last drawable in ScrollList.
     *
     * @return The distance after the last drawable in the ScrollList.
     *
     * @see setPadding, getPaddingBefore
     */
    int16_t getPaddingAfter() const;

    /**
     * Set snapping. If snapping is false, the items can flow freely. If snapping is true,
     * the items will snap into place so an item is always in the "selected" spot.
     *
     * @param  snap true to snap.
     *
     * @see getSnapping
     */
    void setSnapping(bool snap);

    /**
     * Gets the current snap stetting.
     *
     * @return true if snapping is set, false otherwise.
     *
     * @see setSnapping
     */
    bool getSnapping() const;

    /**
     * Gets an item.
     *
     * @param  drawableIndex Zero-based index of the drawable.
     *
     * @return The item.
     */
    int16_t getItem(int16_t drawableIndex)
    {
        return list.getItemIndex(drawableIndex);
    }

    virtual void handleClickEvent(const ClickEvent& event);

protected:
    virtual int32_t getPositionForItem(int16_t itemIndex);

    virtual int32_t getNearestAlignedOffset(int32_t offset) const;

    virtual int32_t keepOffsetInsideLimits(int32_t newOffset, int16_t overShoot) const;

    int16_t paddingAfterLastItem; ///< The distance after last item
    bool snapping;                ///< Is snapping enabled?
    int windowSize;               ///< Number of items that should always be visible
};

} // namespace touchgfx

#endif // TOUCHGFX_SCROLLLIST_HPP
